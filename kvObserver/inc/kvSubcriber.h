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

typedef enum TypePaperSub_st
{
  DAILY_PAPER,
  WEEK_PAPER,
  MONTH_PAPER,
  YEAR_PAPER,
}TypePaperSub_t;

typedef void (*Notify) (void *);

typedef struct Subcriber_st
{
    TypePaperSub_t subType;
    Notify notify;
}Subscriber_t;


void kvSubscriberInit(Subscriber_t **newSub,void *registerEditorial,TypePaperSub_t type);

#endif /* EDITORIALSUBCRIBER_KVOBSERVER_INC_KVSUBCRIBER_H_ */
