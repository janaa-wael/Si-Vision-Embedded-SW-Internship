/*
 * Viewer.cpp
 *
 *  Created on: Jul 15, 2025
 *      Author: Jana Wael
 */

#include <iostream>
#include "Viewer.h"
#include "DatabaseAccess.h"
using namespace std;

//class DatabaseAccess; // Hint to compiler that a class of name DatabaseAccess exists.

Viewer::Viewer() {
	// TODO Auto-generated constructor stub

}

Viewer::~Viewer() {
	// TODO Auto-generated destructor stub
}

Viewer::Viewer(const Viewer &other) {
	// TODO Auto-generated constructor stub

}

void Viewer::display(const DatabaseAccess& object)
{
	cout << "Data 1: " << object.data1 << endl;
	cout << "Data 2: " << object.data2 << endl;
}
