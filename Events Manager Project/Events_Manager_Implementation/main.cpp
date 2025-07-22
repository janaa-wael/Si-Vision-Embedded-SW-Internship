/*
 * main.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */


#include <iostream>
#include "EventGenerator.h"
using namespace std;

/********Testing Event Generator ********/
int main()
{
	EventGenerator* eg = new EventGenerator(1);
	eg->run();
	this_thread::sleep_for(std::chrono::seconds(5));
	eg->stop();
}

