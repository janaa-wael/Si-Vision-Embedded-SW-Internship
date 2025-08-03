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

#define FREQUENCY_OF_GENERATION		1
#define RUNNING_TIME				20
int main()
{
	EventGenerator eg(FREQUENCY_OF_GENERATION,RUNNING_TIME);
	eg.start();

	eg.waitForStop();

}

