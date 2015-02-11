/*
 * kvSaigonEditorial.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */
#include <stdlib.h>
#include "../inc/kvEditorial.h"
#include "../inc/kvSubcriber.h"

Editorial_t *editorialSaigon;
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
void subListAddElementAtFirst(SubscriberList_t **subList, Subscriber_t *sub);
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
ErrorCode_t subListRemoveElementBasedIndex(SubscriberList_t **list,UInt32 index);
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


void kvEditorialAddNewSubscrible(Subscriber_t *newSubcriber);
void kvEditorialRemoveSubscriber(Subscriber_t *removeSubscriber);
ErrorCode_t kvEditorialInit();
void kvEditorialDeliveryNewMagazing(void *object);
void *kvGetThisEditorial();

void subListAddElementToLast(Subscriber_t *sub,SubscriberList_t *headList)
{

  SubscriberList_t *current;

  current = headList;
  lengthOfSubList += 1;

  while(current->nextSub != NULL)
  {
    current = current->nextSub;
  }

  current->nextSub = malloc(sizeof(SubscriberList_t));
  current->nextSub->sub = sub;
  current->nextSub->nextSub = NULL;
}

void subListAddElementAtFirst(SubscriberList_t **subList, Subscriber_t *sub)
{
  SubscriberList_t *newSub;
  newSub = (SubscriberList_t *)malloc(sizeof(SubscriberList_t));
  newSub->sub = sub;
  newSub->nextSub = *subList;
  *subList = newSub;
}

ErrorCode_t subListRemoveElementBasedIndex(SubscriberList_t **list,UInt32 index)
{
  ErrorCode_t errCode = ERROR_NONE;
  SubscriberList_t *currentSub = *list;
  SubscriberList_t *tempSub = (SubscriberList_t*) NULL;

  lengthOfSubList -=1;

  while (index--)
  {
    if (currentSub->nextSub==NULL)
    {
      errCode = ERROR_BAD_PARAMETER;
      return errCode;
    }
    currentSub = currentSub->nextSub;
  }

  tempSub = currentSub->nextSub;
  currentSub->nextSub =  tempSub->nextSub;
  free(tempSub);

  return errCode;
}

UInt32 subListIndexof(SubscriberList_t *listHead,Subscriber_t *sub)
{
  UInt32 index = 0;
  SubscriberList_t *currentSub = listHead;

  while (sub != currentSub->sub) // If address of sub is equal with a address of subscriber
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


ErrorCode_t kvEditorialRegisterInterface(ThisEditorial_t *thisEditorial)
{
  ErrorCode_t errCode = ERROR_NONE;

  thisEditorial->getInstanceRef = kvGetThisEditorial;
  thisEditorial->init = kvEditorialInit;

  editorialSaigon = malloc(sizeof (Editorial_t));
  if(editorialSaigon == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
    return errCode;
  }

  thisEditorial->editorial = editorialSaigon;
  return ERROR_NONE;
}


ErrorCode_t kvEditorialInit()
{
  ErrorCode_t errCode = ERROR_NONE;

  subList = malloc(sizeof(SubscriberList_t));
  if (subList == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
        return errCode;
  }

  subList->nextSub = NULL;

  editorialSaigon->registerNewSubscriber = kvEditorialAddNewSubscrible;
  editorialSaigon->removeSubscriber = kvEditorialRemoveSubscriber;
  editorialSaigon->deliverNewSpaper = kvEditorialDeliveryNewMagazing;

  return errCode;
}

void kvEditorialAddNewSubscrible(Subscriber_t *newSubcriber)
{
  subListAddElementAtFirst(&subList,newSubcriber);
}

void kvEditorialRemoveSubscriber(Subscriber_t *removeSubscriber)
{
  // Get index of the current subscriber
  UInt32 index = 0;
  index = subListIndexof(subList,removeSubscriber);
  // Remove the subscriber based the index
  subListRemoveElementBasedIndex(&subList,index);
}


void kvEditorialDeliveryNewMagazing(void *object)
{
  SubscriberList_t *current = subList;
  UInt8 *typeNewspaper;

  while(current->nextSub != NULL)
  {
    switch (current->sub->subType)
    {
      case DAILY_PAPER:
        typeNewspaper = "DAILY NEWSPAPER";
        break;
      case WEEK_PAPER:
        typeNewspaper = "WEEKLY NEWSPAPER";
        break;
      default:
        typeNewspaper = "DAILY NEWSPAPER";
        break;
    }
      current->sub->notify(typeNewspaper);
      current = current->nextSub;
  }
}



void *kvGetThisEditorial()
{
  return (void*)editorialSaigon;
}


