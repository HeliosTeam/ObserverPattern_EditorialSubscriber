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

  kvSubscriberInit(&kevin,thisEditorial.editorial);
  kvSubscriberInit(&Linda,thisEditorial.editorial);

  thisEditorial.editorial->deliverNewSpaper(NULL);

  thisEditorial.editorial->removeSubscriber(kevin);

  thisEditorial.editorial->deliverNewSpaper(NULL);


  return 1;

}
