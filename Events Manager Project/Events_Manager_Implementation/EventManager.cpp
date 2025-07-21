/*
 * EventManager.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "EventManager.h"
#include <iostream>
using namespace std;

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

EventManager::~EventManager() {
	cout << "Event Manager Destructor is called" << endl;
}

