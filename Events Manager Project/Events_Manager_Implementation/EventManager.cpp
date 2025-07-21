/*
 * EventManager.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "EventManager.h"
#include <iostream>
#include "SystemEvent.h"
#include <thread>
#include <chrono>
using namespace std;

/***************************************	Static Data Members		***************************************/
bool EventManager::isCreated = false;
EventManager* EventManager::instance = nullptr;


EventManager::EventManager()
{
	cout << "Event Manager Private Default Constructor is called" << endl;

}

EventManager* EventManager::getInstance()
{
	if(!isCreated)
	{
		instance = new EventManager();
	}
	return instance;
}

void EventManager::postEvent(Event* e)
{
	if(e != nullptr)
	{
		e->executeEvent();
	}
}

void EventManager::getMaxPriorityEvent(Event* e)
{
	while(1)
	{
		if(!pq.empty())
		{
			e = pq.top();
			e->executeEvent();
			pq.pop();
		}
		else
			e = nullptr;
		std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for 1 sec

	}
}

void EventManager::startHandlingEvents()
{
	Event* em = new SystemEvent();
	thread t1(&EventManager::getMaxPriorityEvent);
}

void EventManager::stopHandlingEvents()
{

}

EventManager::~EventManager() {
	cout << "Event Manager Destructor is called" << endl;
}

