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

void kvSubscriberInit(Subscriber_t **newSub,void *registerEditorial)
{
  Editorial_t *thisEditorial = (Editorial_t *)registerEditorial;

  *newSub = (Subscriber_t*) malloc(sizeof (Subscriber_t));
  (*newSub)->notify = kvSubscriberNotify;
  (*newSub)->subType = DAILY_PAPER;

  thisEditorial->registerNewSubscriber(*newSub);

}


void kvSubscriberNotify()
{
  printf("\r\n I am Kevin, My subscribe is Daily paper");
}
