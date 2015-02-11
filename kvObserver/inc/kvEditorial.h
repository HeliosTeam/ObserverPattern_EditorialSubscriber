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


typedef ErrorCode_t (*Init)(Void);
typedef Void (*RegisterNewSubscriber)(Void *);
typedef Void (*RemoveSubscriber)(Void *);
typedef Void (*DeliverNewSpaper)(Void *);
typedef Void *(*GetReferenceOfInstance)(Void*);


typedef struct Editorial_st
{
    RegisterNewSubscriber registerNewSubscriber;
    RemoveSubscriber removeSubscriber;
    DeliverNewSpaper deliverNewSpaper;
}Editorial_t;

typedef struct ThisEditorial_st
{
    Init init;
    Editorial_t *editorial;
    struct subscriberList_st *subList;
}ThisEditorial_t;

ErrorCode_t kvEditorialRegisterInterface(ThisEditorial_t *thisEditorial);

#endif /* EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_ */
