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
	EventGenerator eg(1);
	eg.start();
	eg.waitForStop();
}

