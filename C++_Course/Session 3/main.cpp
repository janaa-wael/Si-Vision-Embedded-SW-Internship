/*
 * main.cpp
 *
 *  Created on: Jul 15, 2025
 *      Author: hp
 */


#include <iostream>
#include "MyClass.h"
using namespace std;

class Dummy{
private:
	int firstEmpty=0;
	static int callCount; // tied to the class, not a specific object! -> Declaration
	int* arr;
public:
	Dummy() : firstEmpty(0), arr(new int[10])
	{

	}
	void addNumber(const int inputNum)
	{
		arr[firstEmpty] = inputNum;
		firstEmpty++;
	}
	int getNumber(void)
	{
		callCount++;
		cout << "Function has been called " << callCount << " times" << endl;
		int randNum = 20;
		return randNum;
	}
	int sum(int x, int y)
	{
		return x+y;
	}
	static void print()
	{
		callCount++;
	}
};

//Singleton Design Pattern

class Class
{
private:
	static bool isCreated;
	static Class& instance;
	Class()
	{

	}
	Class(const Class& other) = delete;
public:
	static Class& getInstance(void)
	{
		static Class obj;
		return obj;
	}
};
//Define Class
// 1. Define the class in a shared file
// 2. Create a header file and define the class there
// 3. Create a header file file and a source file

int Dummy::callCount = 0; // :: Scope Resolution Operator - Definition
int main()
{
	cout << "Starting .. \n" << endl;
	MyClass ob;
	ob.func();
	Class c1 = Class::getInstance();
	Class c2= Class::getInstance();
	c2 = c2; //Copy ctor is private, to geenrate a compilation error when trying to create another instance
	/*	Dummy ob;
	ob.addNumber(1);
	ob.addNumber(2);
	ob.addNumber(3);
	ob.getNumber();
	ob.getNumber();
	ob.getNumber();
	ob.sum(0x55, 0x66);*/

	//00007ff71390181c:   mov     $0x66,%edx
	//00007ff713901821:   mov     $0x55,%ecx
}

