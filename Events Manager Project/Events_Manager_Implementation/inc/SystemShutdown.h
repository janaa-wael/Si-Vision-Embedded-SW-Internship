/*
 * SystemShutdown.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef SYSTEMSHUTDOWN_H_
#define SYSTEMSHUTDOWN_H_
#include "SystemEvent.h"

class SystemShutdown : public SystemEvent {
public:
	SystemShutdown();
	SystemShutdown(int priority);
	void executeEvent() override;
	virtual ~SystemShutdown();
};

#endif /* SYSTEMSHUTDOWN_H_ */
