/*
 * HWReceivePacket.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "HWReceivePacket.h"
#include <iostream>
using namespace std;

HWReceivePacket::HWReceivePacket() {
	cout << "Hardware Receive Packet Constructor is called" << endl;
}

HWReceivePacket::HWReceivePacket(int priority) : HardwareEvent(priority)
{

}

void HWReceivePacket::HWReceivePacket::executeEvent()
{
	cout << "Packet receive through Hardware successfully" << endl;
}


HWReceivePacket::~HWReceivePacket() {
	cout << "Hardware Receive Packet Destructor is called" << endl;
}

