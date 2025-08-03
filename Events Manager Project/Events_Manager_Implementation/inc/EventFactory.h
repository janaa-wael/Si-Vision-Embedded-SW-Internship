/*
 * EventFactory.h
 *
 *  Created on: Jul 27, 2025
 *      Author: hp
 */

#ifndef EVENTFACTORY_H_
#include <stdlib.h>
#define EVENTFACTORY_H_
#include "Event.h"

#define MAX_PRIORITY		100
#define RANDOM_PRI			rand()%5

class EventFactory {
public:
	EventFactory();
	static Event* createEvent(int type);
	virtual ~EventFactory();
};

#endif /* EVENTFACTORY_H_ */
