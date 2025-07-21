/*
 * EventGenerator.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "EventGenerator.h"
#include <iostream>
#include <thread>
using namespace std;

EventGenerator::EventGenerator() {
	cout << "Event Generator Constructor is called" << endl;

}

Event* EventGenerator::generateRandomEvent()
{
	int rnd = rand()%5;
	return mp[rnd];
}

void start()
{
	EventGenerator* eg;
	thread t1();
}
void stop()
{

}

EventGenerator::~EventGenerator() {
	cout << "Event Generator Destructor is called" << endl;
}

