/*
 * kvEditorial.h
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#ifndef EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_
#define EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_

#include "../../kvInclude/kvInclude.h"
#include "../inc/kvSubcriber.h"

typedef struct subscriberList_st
{
    Subscriber_t *sub;
    struct subscriberList_st *nextSub;
}SubscriberList_t;


typedef ErrorCode_t (*Init)(void);
typedef void (*RegisterNewSubscriber)(void *);
typedef void (*RemoveSubscriber)(void *);
typedef void (*DeliverNewSpaper)(void *);
typedef void *(*GetReferenceOfInstance)(void*);


typedef struct Editorial_st
{
    RegisterNewSubscriber registerNewSubscriber;
    RemoveSubscriber removeSubscriber;
    DeliverNewSpaper deliverNewSpaper;
}Editorial_t;

typedef struct ThisEditorial_st
{
    Init init;
    GetReferenceOfInstance getInstanceRef;
    Editorial_t *editorial;
}ThisEditorial_t;

ErrorCode_t kvEditorialRegisterInterface(ThisEditorial_t *thisEditorial);

#endif /* EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_ */
