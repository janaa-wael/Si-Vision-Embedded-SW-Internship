/*
 * EventManager.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "EventManager.h"
#include <iostream>
#include "HWSendPacket.h"
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

/***************************************	Static Data Members		***************************************/
bool EventManager::isCreated = false;
EventManager* EventManager::instance = nullptr;


EventManager::EventManager()
{
	cout << "Event Manager Private Default Constructor is called" << endl;;
	scheduling_thread = thread(&EventManager::startHandlingEvents, this);
	stopScheduling_thread = thread(&EventManager::stopHandlingEvents, this);
}

/* Applying Singleton Pattern */
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
		pq.push(e);
	}
}

void EventManager::getMaxPriorityEvent(Event* e)
{
	if(!pq.empty())
	{
		e = pq.top();
		e->executeEvent();
		pq.pop();
	}
	else
		e = nullptr;
}

void EventManager::startHandlingEvents()
{

	running = true;
	while(running)
	{
		if(!pq.empty())
		{
			Event* e = pq.top();
			pq.pop();
			e->executeEvent();
		}
		std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for 1 sec
	}
}

void EventManager::stopHandlingEvents()
{
	this_thread::sleep_for(chrono::seconds(10));
	running = false;
	if(scheduling_thread.joinable()) scheduling_thread.join();
}

EventManager::~EventManager() {
	cout << "Event Manager Destructor is called" << endl;
	if(stopScheduling_thread.joinable()) stopScheduling_thread.join();
}

