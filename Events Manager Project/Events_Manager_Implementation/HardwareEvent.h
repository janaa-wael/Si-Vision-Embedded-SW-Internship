/*
 * HardwareEvent.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef HARDWAREEVENT_H_
#define HARDWAREEVENT_H_
#include "Event.h"

class HardwareEvent : public Event{
public:
	HardwareEvent();
	virtual void executeEvent() = 0;
	void setUpHardware();
	virtual ~HardwareEvent();
};

#endif /* HARDWAREEVENT_H_ */
