/*
 * SystemWakeup.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "SystemWakeup.h"
#include <iostream>
using namespace std;

SystemWakeup::SystemWakeup() {
	cout << "System Wakeup constructor is called" << endl;

}

SystemWakeup::SystemWakeup(int priority) : SystemEvent(priority)
{

}
void SystemWakeup::executeEvent()
{
	setUpSystem();
	cout << "System successfully transitioned to Wakeup mode" << endl;

}

SystemWakeup::~SystemWakeup() {
	cout << "System Wakeup Destructor is called" << endl;
}

