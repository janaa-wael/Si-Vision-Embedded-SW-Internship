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

#define MAX_PRIORITY		100
#define RADNOM_PRI			rand()%5
class EventGenerator {
private:
	atomic<bool> running = false;
	thread run_thread;
	thread stop_thread;
	int frequency;
	int total_running_time;
	map <int, Event*> mp = {
			{0, new HWSendPacket(RADNOM_PRI)},
			{1, new HWReceivePacket(RADNOM_PRI)},
			{2, new SystemWakeup(RADNOM_PRI)},
			{3, new SystemSleep(RADNOM_PRI)},
			{4, new SystemShutdown(RADNOM_PRI)}
	};
	EventManager* em;
	Event* Current_Event;
public:
	EventGenerator();
	EventGenerator(int frequency,int run_time);
	Event* generateRandomEvent();
	void start();
	void stop();
	void run();
	void waitForStop();
	virtual ~EventGenerator();
};

#endif /* EVENTGENERATOR_H_ */
