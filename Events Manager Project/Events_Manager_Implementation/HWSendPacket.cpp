/*
 * HWSendPacket.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "HWSendPacket.h"
#include "HardwareEvent.h"

#include <iostream>
using namespace std;

HWSendPacket::HWSendPacket() {
	cout << "Hardware Send Packet Default Constructor is being called." << endl;
}

void HWSendPacket::executeEvent()
{
	HardwareEvent::setUpHardware();
	cout << "Packet successfully sent through hardware" << endl;
}


HWSendPacket::~HWSendPacket() {
	cout << "Hardware Send Packet Destructor is being called." << endl;
}

