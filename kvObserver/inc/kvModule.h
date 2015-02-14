/*
 * kvSubcriber.h
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#ifndef EDITORIALSUBCRIBER_KVOBSERVER_INC_KVSUBCRIBER_H_
#define EDITORIALSUBCRIBER_KVOBSERVER_INC_KVSUBCRIBER_H_

#include "../../kvInclude/kvInclude.h"
#include "../inc/kvHost.h"

typedef enum TypePaperSub_en
{
  DAILY_PAPER,
  WEEK_PAPER,
  MONTH_PAPER,
  YEAR_PAPER,
}TypePaperSub_t;

typedef enum UpdateFlag_en
{
	UPDATE_SET,
	UPDATE_RESET,
}UpdateFlag_t;

/**
 * Function pointer point to function init
 * @param: instance of Host. Registe module to the Host
 */
typedef Void (*ModuleInit) (Void *);

typedef Void (*UpdateProcess) (Void *);


typedef struct Module_st
{
	ModuleInit init;
	UpdateFlag_t change;
    TypePaperSub_t subType;
    UpdateProcess update;
} Module_t;

Void kvModuleRegisterInterface(Module_t *Module);

Void *kvModuleProximityRegisterInterface(Module_t **newModule);


Void kvModuleInit(Module_t **newModule,Void *HostRegister,TypePaperSub_t type);

Void kvModuleResetCHangedFlag(Void *sub);

Void kvModuleSetChangedFlag(Void *sub);

#endif /* EDITORIALSUBCRIBER_KVOBSERVER_INC_KVSUBCRIBER_H_ */
