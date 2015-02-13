/*
 * kvSubcriber.h
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#ifndef EDITORIALSUBCRIBER_KVOBSERVER_INC_KVSUBCRIBER_H_
#define EDITORIALSUBCRIBER_KVOBSERVER_INC_KVSUBCRIBER_H_

#include "../../kvInclude/kvInclude.h"
#include "../inc/kvEditorial.h"

typedef enum TypePaperSub_en
{
  DAILY_PAPER,
  WEEK_PAPER,
  MONTH_PAPER,
  YEAR_PAPER,
}TypePaperSub_t;

typedef enum ChangedFlag_en
{
	SET,
	RESET,
}ChangedFlag_t;

typedef Void (*Notify) (Void *);

typedef Void (*ResetChangedFlash)(Void *);
typedef Void (*SetChangedFlash)(Void *);

typedef struct Subcriber_st
{
	ChangedFlag_t change;
	ResetChangedFlash resetFlag;
	SetChangedFlash setFlag;
    TypePaperSub_t subType;
    Notify notify;
} Subscriber_t;


Void kvSubscriberInit(Subscriber_t **newSub,Void *registerEditorial,TypePaperSub_t type);

#endif /* EDITORIALSUBCRIBER_KVOBSERVER_INC_KVSUBCRIBER_H_ */
