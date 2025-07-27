/*
 * EventManager.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_
#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include "Event.h"
using namespace std;


class EventManager {
private:
	int sleeptime;
	struct comparator{
		bool operator()(Event* e1, Event* e2)
		{
			return e1->getPriority() > e2->getPriority();
		}
	};
	bool running = false;
	mutex mtx;
	EventManager();
	EventManager(int sleeptime);
	priority_queue <Event*, vector<Event*>, comparator> pq;
	static EventManager* instance;
	static bool isCreated;
	thread scheduling_thread;
	thread stopScheduling_thread;
public:
	static EventManager* getInstance();
	void setSleeptime(int sleeptime);
	void postEvent(Event* e);
	void startHandlingEvents();
	void stopHandlingEvents();
	void getMaxPriorityEvent(Event* e);

	virtual ~EventManager();
};

#endif /* EVENTMANAGER_H_ */
