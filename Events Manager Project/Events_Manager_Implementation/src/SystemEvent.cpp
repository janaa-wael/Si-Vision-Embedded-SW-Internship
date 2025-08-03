/*
 * SystemEvent.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "SystemEvent.h"
#include <iostream>
using namespace std;
SystemEvent::SystemEvent() {
	cout << "System Event Constructor is called" << endl;
}

SystemEvent::SystemEvent(int priority) : Event(priority)
{

}
void SystemEvent::setUpSystem()
{
	cout << "Set Up System function is being executed" << endl;
}


SystemEvent::~SystemEvent() {
	cout << "System Event Destructor is called" << endl;
}

