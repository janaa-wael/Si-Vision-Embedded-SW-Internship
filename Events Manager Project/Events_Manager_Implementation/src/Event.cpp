/*
 * Event.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "Event.h"
#include <iostream>
using namespace std;
Event::Event()
{
	cout << "Event Constructor called" << endl;
}

Event::Event(int priority)
{
	this->priority = priority;
}

int Event::getPriority()
{
	return priority;
}


Event::~Event()
{
	cout << "Event Destructor called" << endl;
}

