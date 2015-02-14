/*
 * kvSaigonEditorial.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */
#include <stdlib.h>
#include "../inc/kvHost.h"
#include "../inc/kvModule.h"

ModuleList_t *subList;
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
Void subListAddElementAtFirst(ModuleList_t **subList, Module_t *sub);
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
ErrorCode_t subListRemoveElementBasedIndex(ModuleList_t **list,UInt32 index);
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
UInt32 subListIndexof(ModuleList_t *list,Module_t *sub);
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
UInt32 subListLength(ModuleList_t *list);

ErrorCode_t kvEditorialInit();
Void kvEditorialAddNewSubscrible(Void *newSubcriber);
Void kvEditorialRemoveSubscriber(Void *removeSubscriber);
Void kvEditorialDeliveryNewMagazing(Void *object);

Void subListAddElementAtLast(ModuleList_t *headList,Module_t *sub)
{

  ModuleList_t *current;

  current = headList;
  lengthOfSubList += 1;

  while(current->nextSub != NULL)
  {
    current = current->nextSub;
  }

  if (current->sub == NULL)
  {
	  current->sub = sub;
  }
  else
  {
	  current->nextSub = malloc(sizeof(ModuleList_t));
	  current->nextSub->sub = sub;
	  current->nextSub->nextSub = NULL;
  }
}

Void subListAddElementAtFirst(ModuleList_t **subList, Module_t *sub)
{
  ModuleList_t *newSub;
  newSub = (ModuleList_t *)malloc(sizeof(ModuleList_t));
  newSub->sub = sub;
  newSub->nextSub = *subList;
  *subList = newSub;
}

ErrorCode_t subListRemoveElementBasedIndex(ModuleList_t **list,UInt32 index)
{
  ErrorCode_t errCode = ERROR_NONE;
  ModuleList_t *currentSub = *list;
  ModuleList_t *tempSub = (ModuleList_t*) NULL;

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

UInt32 subListIndexof(ModuleList_t *listHead,Module_t *sub)
{
  UInt32 index = 0;
  ModuleList_t *currentSub = listHead;

  while (sub != currentSub->sub) // If address of sub is equal with a address of subscriber
  {
    currentSub = currentSub->nextSub;
    index ++;
  }

  return index;
}

UInt32 subListLength(ModuleList_t *head)
{
  ModuleList_t *current = head;
  UInt32 count = 0;

  while (current ->nextSub != NULL)
  {
    count++;
  }

  return count;
}


ErrorCode_t kvHostRegisterInterface(ThistHost_t *thistHost)
{
  ErrorCode_t errCode = ERROR_NONE;

  thistHost->init = kvEditorialInit;
  thistHost->host = malloc(sizeof (Host_t));

  if(thistHost->host == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
    return errCode;
  }

  return ERROR_NONE;
}


ErrorCode_t kvEditorialInit(Void *thisEditorial)
{
  ErrorCode_t errCode = ERROR_NONE;

  ThistHost_t *this = (ThistHost_t *) thisEditorial;

  Host_t *editorialInf = this->host;

  this->subList =  malloc(sizeof(ModuleList_t));

  subList = this->subList;
  subList->sub = NULL;

  if (subList == NULL)
  {
    errCode = ERROR_BAD_ALLOCATE_MEM;
        return errCode;
  }

  subList->nextSub = NULL;

  editorialInf->registeNewModule = kvEditorialAddNewSubscrible;
  editorialInf->removeModule = kvEditorialRemoveSubscriber;
  editorialInf->update = kvEditorialDeliveryNewMagazing;

  return errCode;
}

Void kvEditorialAddNewSubscrible(Void *newSubcriber)
{
  subListAddElementAtLast(subList,(Module_t*)newSubcriber);
}

Void kvEditorialRemoveSubscriber(Void *removeSubscriber)
{
  // Get index of the current subscriber
  UInt32 index = 0;
  index = subListIndexof(subList,(Module_t *)removeSubscriber);
  // Remove the subscriber based the index
  subListRemoveElementBasedIndex(&subList,index);
}


Void kvEditorialDeliveryNewMagazing(Void *object)
{
  ModuleList_t *current = subList;
  Int8 *typeNewspaper;

  do
  {
	if (current->sub->change == UPDATE_SET)
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
		current->sub->update(typeNewspaper);
		kvModuleResetCHangedFlag(current->sub);
	}
    current = current->nextSub;
  }while(current != NULL);
}

