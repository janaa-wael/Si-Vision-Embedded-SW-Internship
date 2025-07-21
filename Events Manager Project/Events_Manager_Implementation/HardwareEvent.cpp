/*
 * HardwareEvent.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */
#include <iostream>
#include "HardwareEvent.h"
using namespace std;

HardwareEvent::HardwareEvent() {
	cout << "Hardware Default Constructor is called" << endl;

}

void HardwareEvent::setUpHardware()
{
	cout << "Set Up Hardware Function is being executed." << endl;
}

HardwareEvent::~HardwareEvent() {
	cout << "Hardware Default Destructor is called" << endl;
}

