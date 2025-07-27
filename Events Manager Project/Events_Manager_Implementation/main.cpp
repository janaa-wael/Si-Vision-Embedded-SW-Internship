/*
 * main.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */


#include <iostream>
#include "EventGenerator.h"
#include "EventManager.h"
using namespace std;

/********Testing Event Generator with Event Manager ********/
int main()
{
	EventGenerator eg(1,10);
	//EventManager* em = EventManager::getInstance();
	eg.start();
	eg.waitForStop();

}

