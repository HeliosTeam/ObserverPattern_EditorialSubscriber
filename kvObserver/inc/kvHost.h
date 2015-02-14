/*
 * kvEditorial.h
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#ifndef EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_
#define EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_

#include "../../kvInclude/kvInclude.h"
#include "../inc/kvModule.h"

typedef struct ModuleList_st
{
	struct Module_st *curModule;
    struct ModuleList_st *nextModule;
}ModuleList_t;


typedef ErrorCode_t (*HostInit)(Void *);
typedef Void (*RegisteNewModule)(Void *);
typedef Void (*UnregisteModule)(Void *);
typedef Void (*Update)(Void *);
typedef Void *(*GetReferenceOfInstance)(Void*);


typedef struct Host_st
{
    RegisteNewModule registeNewModule;
    UnregisteModule removeModule;
    Update update;
}Host_t;

typedef struct ThisHost_st
{
    HostInit init;
    Host_t *host;
    struct ModuleList_st *moduleList;
}ThistHost_t;

ErrorCode_t kvHostRegisterInterface(ThistHost_t *thisHost);

#endif /* EDITORIALSUBCRIBER_KVOBSERVER_INC_KVEDITORIAL_H_ */
