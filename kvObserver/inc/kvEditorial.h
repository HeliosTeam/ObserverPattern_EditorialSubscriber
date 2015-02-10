/*
 * kvEditorial.h
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#ifndef EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_
#define EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_

#include "../../kvInclude/kvInclude.h"

typedef struct subscriberList_st
{
    Subscriber_t *sub;
    SubscriberList_t *nextSub;
}SubscriberList_t;

typedef Void (*RegisterNewSubscriber)(Void *);
typedef Void (*RemoveSubscriber)(Void *);
typedef Void (*DeliverNewSpaper)(Void *);
typedef Void *(*GetReferenceOfInstance)(Void*);


typedef struct editorial_st
{
    RegisterNewSubscriber registerNewSubscriber;
    RemoveSubscriber removeSubscriber;
    DeliverNewSpaper deliverNewSpaper;
    GetReferenceOfInstance getInstanceRef;
}Editorial_t;


Void *kvGetThisEditorial();

#endif /* EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_ */
