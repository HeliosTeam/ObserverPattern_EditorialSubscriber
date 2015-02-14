/*
 * kvProximity.c
 *
 *  Created on: Feb 14, 2015
 *      Author: root
 */

#include <stdlib.h>
#include <stdio.h>
#include "kvProximity.h"



Proximity_t *thisProximity;

Void kvModuleProximityInit(Void *host);
Void kvModuleProximityProcess(Void *object);

Void *kvModuleProximityRegisterInterface(Module_t **newModule)
{
	if (thisProximity == NULL)
	{
		thisProximity = (Proximity_t *) malloc(sizeof(Proximity_t));
		*newModule = &thisProximity->proximity;

		thisProximity->proximity.init = kvModuleProximityInit;
		thisProximity->proximity.change = UPDATE_RESET;
		thisProximity->proximity.subType = DAILY_PAPER;
		thisProximity->proximity.moduleUpdate = kvModuleProximityProcess;
	}
	return thisProximity;
}

Void kvModuleProximityInit(Void *host)
{
	Host_t *thisHost = (Host_t *)host;

	//TODO add your code want to initial for proximity module
	// Initial some low level driver like I2C, GPIO here
	thisHost->registeNewModule(&thisProximity->proximity);
}

Void kvModuleProximityProcess(Void *object)
{
	printf("Proximity is processing");
}
