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

EventGenerator::EventGenerator(int frequency) : frequency(frequency), em(EventManager::getInstance())
{
	cout << "Event Generator Parameterized Constructor is called with frequency = 1 second" << endl;
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
	run_thread = thread(&EventGenerator::run, this);
	stop_thread = thread(&EventGenerator::stop, this);
	//em->startHandlingEvents();
}

void EventGenerator::stop()
{
	cout << "Stop method is called" << endl;
    this_thread::sleep_for(std::chrono::seconds(10));
	if(!running) return;
	running = false;
	if(run_thread.joinable()) run_thread.join();
	cout << "Events Generation stopped " << endl;
}

void EventGenerator::run()
{
	while(running)
	{
		Event* e = generateRandomEvent();
		em->postEvent(e);
		cout << "Event posted to Event Manager successfully" << endl;
        this_thread::sleep_for(std::chrono::seconds(1));
        //delete e;
	}
}

void EventGenerator::waitForStop()
{
	if(stop_thread.joinable()) stop_thread.join();
}

EventGenerator::~EventGenerator()
{
	cout << "Event Generator Destructor is called" << endl;
	//delete em;
}

