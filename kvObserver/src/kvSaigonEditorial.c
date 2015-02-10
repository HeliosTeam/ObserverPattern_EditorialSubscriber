/*
 * kvSaigonEditorial.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#include "../inc/kvEditorial.h"
#include "../inc/kvSubcriber.h"

Editorial_t *SaigonEditorial;
SubscriberList_t *subList;
static UInt32 lengthOfSubList;

/*==============================================================================
 * @START
 * Function: subListAddElement
 * IN      : sub
 * OUT     : list
 * PRE     : None
 * POST    :
 * RETURN  :
 *
 * INFO    : Add sub element to to list
 *
 * @END
 *============================================================================*/
Void subListAddElement(Subscriber_t *sub,SubscriberList_t *list);
/*==============================================================================
 * @START
 * Function: subListRemoveElement
 * IN      : index  the index of list want to delete
 * OUT     : list
 * PRE     : None
 * POST    :
 * RETURN  :
 *
 * INFO    : remove an element of list base index
 *
 * @END
 *============================================================================*/
ErrorCode_t subListRemoveElementBasedIndex(SubscriberList_t *list,UInt32 index);
/*==============================================================================
 * @START
 * Function: subListIndexof
 * IN      : sub
 *           list
 * OUT     : None
 * PRE     : None
 * POST    :
 * RETURN  : return the index of sub in list
 *
 * INFO    : return the index of sub in list
 *
 * @END
 *============================================================================*/
UInt32 subListIndexof(SubscriberList_t *list,Subscriber_t *sub);
/*==============================================================================
 * @START
 * Function: subListLength
 * IN      : sub
 *           list
 * OUT     : None
 * PRE     : None
 * POST    :
 * RETURN  : return the index of sub in list
 *
 * INFO    : return the index of sub in list
 *
 * @END
 *============================================================================*/
UInt32 subListLength(SubscriberList_t *list);


Void kvEditorialAddNewSubscrible(Subscriber_t *newSubcriber);


Void subListAddElementToLast(Subscriber_t *sub,SubscriberList_t *headList)
{
  lengthOfSubList += 1;
  SubscriberList_t *current = headList;

  while(current->nextSub != NULL)
  {
    current = current->nextSub;
  }

  current->nextSub = malloc(sizeof(SubscriberList_t));
  current->nextSub->sub = *sub;
  current->nextSub->nextSub = NULL;
}

Void subListAddElementAtFirst(SubscriberList_t **subList, Subscriber_t *sub)
{
  SubscriberList_t *newSub;
  newSub = malloc(sizeof(SubscriberList_t));
  newSub->sub = *sub;
  newSub->nextSub = *subList;
  *subList = newSub;
}

ErrorCode_t subListRemoveElementBasedIndex(SubscriberList_t **list,UInt32 index)
{
  lengthOfSubList -=1;
  SubscriberList_t *currentSub = *list;
  SubscriberList_t *tempSub = NULL;

  if(!index)
  {
    return ERROR_BAD_PARAMETER;
  }
  while (index--)
  {
    if (currentSub->nextSub==NULL)
    {
      return ERROR_BAD_PARAMETER;
    }
    currentSub = currentSub->nextSub;
  }

  tempSub = currentSub->nextSub;
  currentSub->nextSub =  tempSub->nextSub;
  free(tempSub);

  return ERROR_NONE;
}

UInt32 subListIndexof(SubscriberList_t *listHead,Subscriber_t *sub)
{
  UInt32 index = 0;
  SubscriberList_t *currentSub = listHead;
  while (sub != currentSub->sub)
  {
    currentSub = currentSub->nextSub;
    index ++;
  }
  return index;
}

UInt32 subListLength(SubscriberList_t *head)
{
  SubscriberList_t *current = head;
  UInt32 count = 0;
  while (current ->nextSub != NULL)
  {
    count++;
  }
  return count;
}

ErrorCode_t kvEditorialInit()
{
  ErrorCode_t errCode = ERROR_NONE;
  SaigonEditorial = malloc(sizeof (Editorial_t));
  if(SaigonEditorial == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
    return errCode;
  }

  if (subList == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
        return errCode;
  }

  subList = malloc(sizeof(SubscriberList_t));
  subList->nextSub = NULL;

  SaigonEditorial->registerNewSubscriber = kvEditorialAddNewSubscrible;
  SaigonEditorial->removeSubscriber = kvEditorialRemoveSubscriber;
  SaigonEditorial->deliverNewSpaper = kvEditorialDeliveryNewMagazing;
  SaigonEditorial->getInstanceRef = kvGetThisEditorial;

  return errCode;
}

Void kvEditorialAddNewSubscrible(Subscriber_t *newSubcriber)
{
   subListAddElement(newSubcriber,subList);
}

Void kvEditorialRemoveSubscriber(Subscriber_t *removeSubscriber)
{
  // Get index of the current subscriber
  UInt32 index = 0;
  index = subListIndexof(subList,removeSubscriber);
  // Remove the subscriber based the index
  subListRemoveElementBasedIndex(*subList,index());
}


Void kvEditorialDeliveryNewMagazing()
{
  SubscriberList_t *current = subList;

  while(current->nextSub != NULL)
  {
    current->sub->notify(NULL);
    current = current->nextSub;
  }

}

Void *kvGetThisEditorial()
{
  return (void*)SaigonEditorial;
}


