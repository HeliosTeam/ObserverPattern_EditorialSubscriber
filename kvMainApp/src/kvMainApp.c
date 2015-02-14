/*
 * kvMainApp.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../../kvInclude/kvInclude.h"
#include "../inc/kvMainApp.h"
#include "../../kvObserver/inc/kvHost.h"
#include "../../kvObserver/inc/kvModule.h"



int main()
{
	Int8 c;
	ThistHost_t *thisHost = NULL;

	Module_t *proximity =NULL;

	thisHost = (ThistHost_t *) malloc(sizeof(ThistHost_t));

	kvHostRegisterInterface(thisHost);

	thisHost->init(thisHost);


	kvModuleProximityRegisterInterface(&proximity);

	proximity->init(thisHost->host);

	kvModuleSetChangedFlag(proximity);

	while (1)
	{
		thisHost->host->update(NULL);

		printf("\r\nPress Any Key to Continue\n");
		c = getchar();
		if (c == 'n') {
			kvModuleSetChangedFlag(proximity);
		}

		if (c == 't')
		{
		}
	}
	return 1;
}
