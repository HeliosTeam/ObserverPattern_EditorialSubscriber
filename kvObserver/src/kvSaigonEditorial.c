/*
 * kvSaigonEditorial.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */
#include <stdlib.h>
#include "../inc/kvEditorial.h"
#include "../inc/kvSubcriber.h"

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
Void subListAddElementAtFirst(SubscriberList_t **subList, Subscriber_t *sub);
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

ErrorCode_t kvEditorialInit();
Void kvEditorialAddNewSubscrible(Void *newSubcriber);
Void kvEditorialRemoveSubscriber(Void *removeSubscriber);
Void kvEditorialDeliveryNewMagazing(Void *object);

Void subListAddElementToLast(SubscriberList_t *headList,Subscriber_t *sub)
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

Void subListAddElementAtFirst(SubscriberList_t **subList, Subscriber_t *sub)
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

  thisEditorial->init = kvEditorialInit;
  thisEditorial->editorial = malloc(sizeof (Editorial_t));

  if(thisEditorial->editorial == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
    return errCode;
  }

  return ERROR_NONE;
}


ErrorCode_t kvEditorialInit(Void *thisEditorial)
{
  ErrorCode_t errCode = ERROR_NONE;

  ThisEditorial_t *this = (ThisEditorial_t *) thisEditorial;

  Editorial_t *editorialInf = this->editorial;

  this->subList =  malloc(sizeof(SubscriberList_t));

  subList = this->subList;

  if (subList == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
        return errCode;
  }

  subList->nextSub = NULL;

  editorialInf->registerNewSubscriber = kvEditorialAddNewSubscrible;
  editorialInf->removeSubscriber = kvEditorialRemoveSubscriber;
  editorialInf->deliverNewSpaper = kvEditorialDeliveryNewMagazing;

  return errCode;
}

Void kvEditorialAddNewSubscrible(Void *newSubcriber)
{
  subListAddElementToLast(subList,(Subscriber_t*)newSubcriber);
}

Void kvEditorialRemoveSubscriber(Void *removeSubscriber)
{
  // Get index of the current subscriber
  UInt32 index = 0;
  index = subListIndexof(subList,(Subscriber_t *)removeSubscriber);
  // Remove the subscriber based the index
  subListRemoveElementBasedIndex(&subList,index);
}


Void kvEditorialDeliveryNewMagazing(Void *object)
{
  SubscriberList_t *current = subList;
  Int8 *typeNewspaper;

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
      case MONTH_PAPER:
        typeNewspaper = "MONTHLY NEWSPAPER";
        break;
      case YEAR_PAPER:
        typeNewspaper = "YEARLY NEWSPAPER";
        break;
      default:
        typeNewspaper = "DAILY NEWSPAPER";
        break;
    }
      current->sub->notify(typeNewspaper);
      current = current->nextSub;
  }
}

