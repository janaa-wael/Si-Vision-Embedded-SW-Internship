/*
 * SystemSleep.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef SYSTEMSLEEP_H_
#define SYSTEMSLEEP_H_
#include "SystemEvent.h"
class SystemSleep : public SystemEvent{
public:
	SystemSleep();
	void executeEvent() override;
	virtual ~SystemSleep();
};

#endif /* SYSTEMSLEEP_H_ */
