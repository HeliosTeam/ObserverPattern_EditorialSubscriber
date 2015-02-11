/*
 * kvMainApp.c
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#include "../../kvInclude/kvInclude.h"
#include "../inc/kvMainApp.h"
#include "../../kvObserver/inc/kvEditorial.h"
#include "../../kvObserver/inc/kvSubcriber.h"

int main()
{

  ThisEditorial_t thisEditorial;
  Subscriber_t *kevin = NULL;
  Subscriber_t *Linda = NULL;

  kvEditorialRegisterInterface(&thisEditorial);

  thisEditorial.init();

  kvSubscriberInit(&kevin,thisEditorial.editorial,DAILY_PAPER);
  kvSubscriberInit(&Linda,thisEditorial.editorial,WEEK_PAPER);

  thisEditorial.editorial->deliverNewSpaper(NULL);

  thisEditorial.editorial->removeSubscriber(kevin);
  thisEditorial.editorial->removeSubscriber(Linda);


  thisEditorial.editorial->deliverNewSpaper(NULL);

  return 1;
}
