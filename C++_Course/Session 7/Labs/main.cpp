/*
 * main.cpp
 *
 *  Created on: Jul 20, 2025
 *      Author: hp
 */

#include <iostream>
using namespace std;

class Parent{
	int* arr;
public:
	Parent()
	{

	}
	Parent(const int size) : arr(new int[size])
	{

	}
	virtual void print()
	{
		cout << "Print function of the base" << endl;
	}

	//Rule of three: Destructor / Copy Constructor / Assignment Operator
	~Parent()
	{
		if(arr != nullptr)
		{
			delete[] arr;
		}
		cout << "Destructor of Parent" << endl;
	}
};

class Child : public Parent{
	int* childArr;
public:
	Child() : childArr(new int[10])
	{
		cout << "Constructor of child" << endl;
	}
	void print(int x)
	{
		cout << "Print function of child" << endl;
	}
	void print()
	{
		cout << "Print function of child." << endl;
	}
	//Reference Qualifier
	//Lvalues object will call this function
	void lvalueFunc() &
	{
		cout << "Lvalue called" << endl;
	}

	//Rvalues will call this function.
	void rvalueFunc() &&
	{
		cout << "Rvalue called" << endl;
	}
	~Child()
	{
		cout << "destructor of Child" << endl;
	}
};
//Clean up functions for resources
void destroyObject(Parent* object)
{
	delete object;
}

// Interface Class: A class that contains only pure virtual functions!
class HWAccess{
/*private:
	bool active;
	HWAccess() : active(false)
	{

	}*/
/*public:
	void SetActive(const bool actie)
	{
		this->active = active;
	}*/
public:
	virtual void init() = 0;
	virtual void send() = 0;
};

class I2C : public HWAccess{
public:
	void init() override
	{
		cout << "I2C Initalized" << endl;
	}
	void send() override
	{

	}
};

class SPI : public HWAccess{
public:
	void init() override
	{
		cout << "SPI is initialized" << endl;
	}
	virtual void send() = 0;

};

class SPI_Child : public SPI
{
public:
	void send() override
	{
		cout << "SPI successfully sent data!" << endl;
	}
};

class UART : public HWAccess
{
public:
	void init() override
	{
	}
	void send() override
	{

	}
};

// Rule: Parent Classes must force some rules on the children classes.
// Extra: Functions that don't make any sense in the Parent class shouldn't be implemented
// Rule: Constructing objects from Parent classes should be prohibited.
void goThroughProcess(HWAccess* ptr)
{
	ptr->init();
	ptr->send();
}
int main()
{
	SPI_Child sppi;
	Child* c1 = new Child;
	destroyObject(c1); // Implicit Upward Casting
	I2C i2c;
}


