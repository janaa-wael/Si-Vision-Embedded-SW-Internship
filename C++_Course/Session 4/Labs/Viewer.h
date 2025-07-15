/*
 * Viewer.h
 *
 *  Created on: Jul 15, 2025
 *      Author: hp
 */

#ifndef VIEWER_H_
#define VIEWER_H_

class DatabaseAccess;

class Viewer {
public:
	Viewer();
	virtual ~Viewer();
	Viewer(const Viewer &other);
	void display(const DatabaseAccess& object);

};

#endif /* VIEWER_H_ */
