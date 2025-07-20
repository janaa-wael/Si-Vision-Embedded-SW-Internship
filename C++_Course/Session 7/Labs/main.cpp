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
class ProtocolBase{
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

class I2C : public ProtocolBase{
public:
	void init() override
	{
		cout << "I2C Initalized" << endl;
	}
	void send() override
	{

	}
	void specialFunc()
	{
		cout << "Special Function of I2C is called" << endl;
	}
};

class SPI : public ProtocolBase{
public:
	SPI()
	{

	}
	void init() override
	{
		cout << "SPI is initialized" << endl;
	}
	virtual void send() override
	{
		cout << "SPI successfully sent data" << endl;
	}

};


class UART : public ProtocolBase
{
public:
	void init() override
	{
	}
	void send() override
	{

	}
};

enum ProtocolTypes{
	SPI_t,
	I2C_t
};


class HWAcess{
private:
	ProtocolBase* protocol;
	ProtocolBase* createProtocol(const ProtocolTypes id)
	{
		if(id == SPI_t)
		{
			return new SPI();
		}
		else
		{
			return new I2C();
		}
	}
public:
	HWAcess(const ProtocolTypes id)
	{
		// Polymorphic Object
		// ParentClass* parentObject = new ChildClass();
		protocol = createProtocol(id);
	}
	void goThroughProcess(ProtocolBase* ptr)
	{
		ptr->init();
		ptr->send();
	}
};
// Rule: Parent Classes must force some rules on the children classes.
// Extra: Functions that don't make any sense in the Parent class shouldn't be implemented
// Rule: Constructing objects from Parent classes should be prohibited.

int main()
{

	//Child* c1 = new Child;
	//destroyObject(c1); // Implicit Upward Casting
	I2C* i2c = new I2C;

	// Upward Casting
	ProtocolBase* protocolBase = i2c;

	// Downward Casting - Downcasting
	I2C* object = static_cast<I2C*>(protocolBase); // Compile-time Checks

	//SPI* spiObject = static_cast<SPI*>(protocolBase);
	SPI* spiObject = dynamic_cast<SPI*>(protocolBase);

	if(spiObject == nullptr)
	{
		cout << "Bad Casting" << endl;
	}
	i2c->specialFunc();
}


