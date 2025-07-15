/*
 * MyClass.h
 *
 *  Created on: Jul 15, 2025
 *      Author: hp
 */

#ifndef MYCLASS_H_
#define MYCLASS_H_

class MyClass {
	static int callCount;
public:
	MyClass();
	virtual ~MyClass();
	MyClass(const MyClass &other);
	void func();
};

#endif /* MYCLASS_H_ */
