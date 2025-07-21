/*
 * SystemSleep.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "SystemSleep.h"
#include <iostream>
using namespace std;

SystemSleep::SystemSleep() {
	cout << "System Sleep Constructor is called" << endl;

}

void SystemSleep::executeEvent()
{
	setUpSystem();
	cout << "System successfully transition to SLEEP mode" << endl;
}


SystemSleep::~SystemSleep() {
	cout << "System Sleep Destructor is called" << endl;
}

