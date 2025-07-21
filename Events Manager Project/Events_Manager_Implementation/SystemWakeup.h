/*
 * SystemWakeup.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef SYSTEMWAKEUP_H_
#define SYSTEMWAKEUP_H_
#include "SystemEvent.h"

class SystemWakeup : public SystemEvent{
public:
	SystemWakeup();
	SystemWakeup(int priority);
	void executeEvent() override;
	virtual ~SystemWakeup();
};

#endif /* SYSTEMWAKEUP_H_ */
