/*
 * kvSubscriber.c
 *
 *  Created on: Feb 14, 2015
 *      Author: root
 */


#include "../inc/kvModule.h"

Void kvModuleResetCHangedFlag(Void *sub)
{
	Module_t *currentSub = (Module_t *)sub;
	currentSub->change = UPDATE_RESET;
}

Void kvModuleSetChangedFlag(Void *sub)
{
	Module_t *currentSub = (Module_t *)sub;
	currentSub->change = UPDATE_SET;
}

Void kvModuleRegisterInterface(Module_t *Module)
{

}
