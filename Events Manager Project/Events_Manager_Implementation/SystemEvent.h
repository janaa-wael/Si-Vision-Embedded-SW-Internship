/*
 * SystemEvent.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef SYSTEMEVENT_H_
#define SYSTEMEVENT_H_
#include "Event.h"

class SystemEvent : public Event{
public:
	SystemEvent();
	virtual void executeEvent() = 0;
	void setUpSystem();
	virtual ~SystemEvent();
};

#endif /* SYSTEMEVENT_H_ */
