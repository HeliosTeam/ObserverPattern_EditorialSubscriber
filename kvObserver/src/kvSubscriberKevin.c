/*
 * kvSubscriberKevin.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#include <stdlib.h>
#include "../inc/kvEditorial.h"
#include "../inc/kvSubcriber.h"


void kvSubscriberNotify();

void kvSubscriberInit(Subscriber_t **newSub,void *registerEditorial,TypePaperSub_t type)
{
  Editorial_t *thisEditorial = (Editorial_t *)registerEditorial;

  *newSub = (Subscriber_t*) malloc(sizeof (Subscriber_t));
  (*newSub)->notify = kvSubscriberNotify;
  (*newSub)->subType = type;
  thisEditorial->registerNewSubscriber(*newSub);

}


void kvSubscriberNotify(void *TypePaper)
{
  UInt8 *paperRec = (UInt8*) TypePaper;

  printf("\r\n I am Kevin, My subscribe is %s",paperRec);
}
