/*
 * MyClass.cpp
 *
 *  Created on: Jul 15, 2025
 *      Author: Jana Wael
 */

#include "MyClass.h"

int MyClass::callCount = 0;
MyClass::MyClass() {
	// TODO Auto-generated constructor stub

}

MyClass::~MyClass() {
	// TODO Auto-generated destructor stub
}

MyClass::MyClass(const MyClass &other) {
	// TODO Auto-generated constructor stub

}

void MyClass::func()
{
	callCount = 10;
}
