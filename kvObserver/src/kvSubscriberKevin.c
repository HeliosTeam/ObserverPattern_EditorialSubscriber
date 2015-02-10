/*
 * kvSubscriberKevin.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */


#include "../inc/kvEditorial.h"
#include "../inc/kvSubcriber.h"

Subscriber_t *subscriberKevin;

void kvSubscriberInit()
{
  subscriberKevin = malloc(sizeof (Subscriber_t));
  subscriberKevin->notify = kvSubscriberNotify;
  subscriberKevin->subType = DAILY_PAPER;

  Editorial_t *myEditorial = (Editorial_t *) kvGetThisEditorial();

  myEditorial->registerNewSubscriber(subscriberKevin);


}


Void kvSubscriberNotify()
{
  printf("\r\n I am Kevin, My subscribe is Daily paper");
}
