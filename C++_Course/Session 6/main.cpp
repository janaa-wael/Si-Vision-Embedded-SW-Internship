/*
 * main.cpp
 *
 *  Created on: Jul 20, 2025
 *      Author: hp
 */

#include <iostream>
using namespace std;

#define TEAM_LEADER			3
#define MANAGER				2
class Level1{
public:
	int var1 = 10;
	int var2 = 20;
};

class Level2 : public Level1{
protected:
	using Level1::var1;
};

class Level3 : public Level2{
public:
	Level3()
	{
		cout << var1 << endl;
		cout << var2 << endl;
	}
};

class Parent{
protected:
	int role;
public:
	int parentNum = 20;
	void print()
	{
		cout << "Parent is called" << endl;
	}
};

class Child1 : public Parent{
public:
	int childNum = 20;
	Child1()
	{
		role = TEAM_LEADER;
	}
	void print()
	{
		cout << "Child is called." << endl;
	}
};

class Child2 : public Parent{
public:
	Child2()
	{
		role = MANAGER;
	}
};

class FinalChild : public Child1, public Child2{
	FinalChild()
	{
		cout << "Role:: " << Child1::role << endl;
		// Which role are you referring to?
	}
};

int main()
{
	// Child >> Parent [Upward Casting]
	// Parent >> Childd [Downward Casting]
	Child1 childObject;

	//Construction of parent class from child class (We only copy the base properties of ChildObject to ParentObject)
	Parent parentObject(childObject);
	int x = 10;
	Parent& refObject = static_cast<Parent&>(childObject); //ref object points to the base
	refObject.print();
}


