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
#include "Event.h"
using namespace std;


class EventManager {
private:
	priority_queue <Event*> pq;
	static EventManager* instance;
	static bool isCreated;
public:
	static EventManager* getInstance();
	virtual ~EventManager();
};

#endif /* EVENTMANAGER_H_ */
