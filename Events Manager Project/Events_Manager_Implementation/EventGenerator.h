/*
 * EventGenerator.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef EVENTGENERATOR_H_
#define EVENTGENERATOR_H_

#include "HWSendPacket.h"
#include "HWReceivePacket.h"
#include "SystemWakeup.h"
#include "SystemSleep.h"
#include "SystemShutdown.h"
#include <map>
using namespace std;

class EventGenerator {
private:
	map <int, Event*> mp = {
			{0, new HWSendPacket()},
			{1, new HWReceivePacket()},
			{2, new SystemWakeup()},
			{3, new SystemSleep()},
			{4, new SystemShutdown()}
	};

public:
	EventGenerator();
	Event* generateRandomEvent();
	void start();
	void stop();
	virtual ~EventGenerator();
};

#endif /* EVENTGENERATOR_H_ */
