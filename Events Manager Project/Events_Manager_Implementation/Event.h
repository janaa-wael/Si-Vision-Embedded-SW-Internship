/*
 * Event.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
	int priority;
public:
	Event();
	Event(int priority);
	virtual void executeEvent() = 0;
	int getPriority();
	virtual ~Event();
};

#endif /* EVENT_H_ */
