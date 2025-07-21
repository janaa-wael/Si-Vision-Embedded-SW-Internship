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
#include "Event.h"
using namespace std;


class EventManager {
private:
	struct comparator{
		bool operator()(Event* e1, Event* e2)
		{
			return e1->getPriority() > e2->getPriority();
		}
	};
	EventManager();
	priority_queue <Event*, vector<Event*>, comparator> pq;
	static EventManager* instance;
	static bool isCreated;
public:
	static EventManager* getInstance();
	void postEvent(Event* e);
	void startHandlingEvents();
	void stopHandlingEvents();
	void getMaxPriorityEvent(Event* e);

	virtual ~EventManager();
};

#endif /* EVENTMANAGER_H_ */
