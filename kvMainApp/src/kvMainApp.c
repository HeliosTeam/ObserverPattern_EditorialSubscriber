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

int main()
{

  ThisEditorial_t *thisEditorial = NULL;
  Subscriber_t *Kevin = NULL;
  Subscriber_t *Linda = NULL;
  Subscriber_t *Jean = NULL;
  Subscriber_t *Petter = NULL;

  thisEditorial = (ThisEditorial_t *) malloc(sizeof(ThisEditorial_t));
  kvEditorialRegisterInterface(thisEditorial);

  thisEditorial->init(thisEditorial);

  kvSubscriberInit(&Kevin,thisEditorial->editorial,DAILY_PAPER);
  kvSubscriberInit(&Linda,thisEditorial->editorial,WEEK_PAPER);
  kvSubscriberInit(&Jean,thisEditorial->editorial,MONTH_PAPER);
  kvSubscriberInit(&Petter,thisEditorial->editorial,YEAR_PAPER);

  thisEditorial->editorial->deliverNewSpaper(NULL);



  return 1;
}
