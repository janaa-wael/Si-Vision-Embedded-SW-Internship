/*
 * EventGenerator.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#include "EventGenerator.h"
#include <iostream>
#include <thread>
#include <future>
using namespace std;

EventGenerator::EventGenerator() : em(EventManager::getInstance())
{
	cout << "Event Generator Constructor is called" << endl;
}

EventGenerator::EventGenerator(int frequency) : frequency(frequency)
{

}

Event* EventGenerator::generateRandomEvent()
{
	int rnd = rand()%5;
	return mp[rnd];
}

void EventGenerator::start()
{
	if(running) return;

	running = true;
	t = thread(&EventGenerator::run, this);
}

void EventGenerator::stop()
{
	if(!running) return;
	running = false;
	if(t.joinable()) t.join();
	cout << "Events Generation stopped " << endl;
}

void EventGenerator::run()
{
	while(running)
	{
		Event* e = generateRandomEvent();
		em->postEvent(e);
		cout << "Event posted to Event Manager successfully" << endl;
        this_thread::sleep_for(std::chrono::milliseconds(frequency*1000));
	}
}

EventGenerator::~EventGenerator()
{
	cout << "Event Generator Destructor is called" << endl;
}

