/*
 * kvSubscriberKevin.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/kvHost.h"
#include "../inc/kvModule.h"




Void kvSubscriberNotify();

Void kvModuleInit(Module_t **newModule,Void *registerHost,TypePaperSub_t type)
{
  Host_t *thisEditorial = (Host_t *)registerHost;

  *newModule = (Module_t*) malloc(sizeof (Module_t));
  (*newModule)->update = kvSubscriberNotify;
  (*newModule)->subType = type;
  (*newModule)->change = UPDATE_RESET;
  thisEditorial->registeNewModule(*newModule);
}

Void kvSubscriberNotify(Void *TypePaper)
{
  UInt8 *paperRec = (UInt8*) TypePaper;
  printf("\r\n I am Kevin, My subscribe is %s",paperRec);
}
