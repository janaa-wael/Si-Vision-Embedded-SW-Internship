/*
 * HWReceivePacket.h
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */

#ifndef HWRECEIVEPACKET_H_
#define HWRECEIVEPACKET_H_
#include "HardwareEvent.h"

class HWReceivePacket : public HardwareEvent{
public:
	HWReceivePacket();
	HWReceivePacket(int priority);
	void executeEvent() override;
	virtual ~HWReceivePacket();
};

#endif /* HWRECEIVEPACKET_H_ */
