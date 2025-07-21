/*
 * HWSendPacket.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef HWSENDPACKET_H_
#define HWSENDPACKET_H_
#include "HardwareEvent.h"

class HWSendPacket : public HardwareEvent{
public:
	HWSendPacket();
	HWSendPacket(int priority);
	void executeEvent() override;
	virtual ~HWSendPacket();
};

#endif /* HWSENDPACKET_H_ */
