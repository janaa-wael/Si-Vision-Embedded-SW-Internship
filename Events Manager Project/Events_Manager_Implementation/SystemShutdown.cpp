/*
 * SystemShutdown.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "SystemShutdown.h"
#include <iostream>
using namespace std;

SystemShutdown::SystemShutdown()
{
	cout << "System Shutdown Constructor is called" << endl;
}

SystemShutdown::SystemShutdown(int priority) : SystemEvent(priority)
{

}
void SystemShutdown::executeEvent()
{
	setUpSystem();
	cout << "System successfully transition to the Shutdown mode" << endl;
}
SystemShutdown::~SystemShutdown() {
	cout << "System Shutdonw Desructor is called" << endl;
}

