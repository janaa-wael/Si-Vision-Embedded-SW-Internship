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
#include "EventFactory.h"
#include <map>
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

class EventGenerator {
private:
	atomic<bool> running = false;
	thread run_thread;
	thread stop_thread;
	int frequency;
	int total_running_time;
	EventManager* em;
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
