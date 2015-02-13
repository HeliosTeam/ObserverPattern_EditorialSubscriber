/*
 * kvMainApp.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#include <stdlib.h>
#include "../../kvInclude/kvInclude.h"
#include "../inc/kvMainApp.h"
#include "../../kvObserver/inc/kvEditorial.h"
#include "../../kvObserver/inc/kvSubcriber.h"

int main() {

	Int8 c;
	ThisEditorial_t *thisEditorial = NULL;
	Subscriber_t *Kevin = NULL;
	Subscriber_t *Linda = NULL;
	Subscriber_t *Jean = NULL;
	Subscriber_t *Petter = NULL;

	thisEditorial = (ThisEditorial_t *) malloc(sizeof(ThisEditorial_t));
	kvEditorialRegisterInterface(thisEditorial);

	thisEditorial->init(thisEditorial);

	kvSubscriberInit(&Kevin, thisEditorial->editorial, DAILY_PAPER);
	kvSubscriberInit(&Linda, thisEditorial->editorial, WEEK_PAPER);
	kvSubscriberInit(&Jean, thisEditorial->editorial, MONTH_PAPER);

	Kevin->setFlag(Kevin);
	Linda->setFlag(Linda);
	Jean->setFlag(Jean);

//  kvSubscriberInit(&Petter,thisEditorial->editorial,YEAR_PAPER);

	while (1) {
		thisEditorial->editorial->deliverNewSpaper(NULL);
		printf("\r\nPress Any Key to Continue\n");
		c = getchar();
		if (c == 'n') {
			Kevin->setFlag(Kevin);
			Linda->setFlag(Linda);
			Jean->setFlag(Jean);
		}

		if (c == 't') {
			Kevin->setFlag(Kevin);
			Linda->setFlag(Linda);
		}

	}
	return 1;
}
