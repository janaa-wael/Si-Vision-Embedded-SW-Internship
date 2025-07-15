/*
 * DatabaseAccess.h
 *
 *  Created on: Jul 15, 2025
 *      Author: hp
 */

#ifndef DATABASEACCESS_H_
#define DATABASEACCESS_H_

#include "Viewer.h"

class DatabaseAccess {
	friend void Viewer::display(const DatabaseAccess& object);
private:
	int data1;
	int data2;
	int data3;
public:
	DatabaseAccess();
	virtual ~DatabaseAccess();
	DatabaseAccess(const DatabaseAccess &other);

};


#endif /* DATABASEACCESS_H_ */
