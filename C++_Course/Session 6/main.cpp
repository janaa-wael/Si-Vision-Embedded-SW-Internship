/*
 * main.cpp
 *
 *  Created on: Jul 20, 2025
 *      Author: hp
 */

#include <iostream>
#include <vector>
using namespace std;

#define TEAM_LEADER			3
#define MANAGER				2
#define SIZE				5
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

enum TaskId {
	TASK_1,
	TASK_2
};

class ParentClass{
	TaskId id;
public:
	ParentClass(const TaskId taskType) : id(taskType)
	{

	}
	int getID(void)
	{
		return id;
	}
};

class Class1 : public ParentClass{
public:
	Class1() : ParentClass(TASK_1)
	{

	}

	void executeClass1Task()
	{
		cout << "Class 1 - Task" << endl;
	}
};

class Class2 : public ParentClass{
public:
	Class2() : ParentClass(TASK_2)
	{

	}
	void executeClass2Task()
	{
		cout << "Class 2 - Task" << endl;
	}
};


// Downcasting
class Container{
	ParentClass** arr;
	int curr = 0;
public:
	// Arr contains pointer to ParentClass objects
	Container(const int size) : arr(new ParentClass*[size])
	{

	}
	void addElement(ParentClass* p)
	{
		arr[curr++] = p;
	}
	void executeFunction()
	{
		for(int i = 0 ; i < SIZE; i++)
		{
			if(arr[i]->getID() == TASK_1)
			{
				Class1* castedObject = static_cast<Class1*>(arr[i]);
				castedObject->executeClass1Task();
			}
			else if(arr[i]->getID() == TASK_2)
			{
				Class2* castedObject = static_cast<Class2*>(arr[i]);
				castedObject->executeClass2Task();
			}
		}
	}
};
int main()
{
	// Child >> Parent [Upward Casting]
	// Parent >> Childd [Downward Casting]
	/*	Child1 childObject;

	//Construction of parent class from child class (We only copy the base properties of ChildObject to ParentObject)
	Parent parentObject(childObject);
	int x = 10;
	Parent& refObject = static_cast<Parent&>(childObject); //Explicit Upward Casting
	//ref object points to the base
	refObject.print();*/

}


