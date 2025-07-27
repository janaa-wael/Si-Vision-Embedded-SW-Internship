/*
 * EventFactory.cpp
 *
 *  Created on: Jul 27, 2025
 *      Author: hp
 */

#include "EventFactory.h"
#include "HWReceivePacket.h"
#include "HWSendPacket.h"
#include "SystemShutdown.h"
#include "SystemWakeup.h"
#include "SystemSleep.h"

EventFactory::EventFactory() {
	// TODO Auto-generated constructor stub

}

Event* EventFactory::createEvent(int type) {
	switch (type) {
	case 0: return new HWSendPacket(RANDOM_PRI);
	case 1: return new HWReceivePacket(RANDOM_PRI);
	case 2: return new SystemWakeup(RANDOM_PRI);
	case 3: return new SystemSleep(RANDOM_PRI);
	case 4: return new SystemShutdown(RANDOM_PRI);
	default: return nullptr;
	}
}

EventFactory::~EventFactory() {
	// TODO Auto-generated destructor stub
}

