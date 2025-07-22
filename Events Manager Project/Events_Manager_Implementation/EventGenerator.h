/*
 * EventGenerator.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef EVENTGENERATOR_H_
#define EVENTGENERATOR_H_
#include "EventManager.h"
#include "HWSendPacket.h"
#include "HWReceivePacket.h"
#include "SystemWakeup.h"
#include "SystemSleep.h"
#include "SystemShutdown.h"
#include <map>
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

class EventGenerator {
private:
	atomic<bool> running;
	thread t;
	int frequency;
	map <int, Event*> mp = {
			{0, new HWSendPacket()},
			{1, new HWReceivePacket()},
			{2, new SystemWakeup()},
			{3, new SystemSleep()},
			{4, new SystemShutdown()}
	};
	EventManager* em;
public:
	EventGenerator();
	EventGenerator(int frequency);
	Event* generateRandomEvent();
	void start();
	void stop();
	void run();
	virtual ~EventGenerator();
};

#endif /* EVENTGENERATOR_H_ */
