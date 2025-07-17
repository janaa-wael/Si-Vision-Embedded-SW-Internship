/*
 * main.cpp
 *
 *  Created on: Jul 17, 2025
 *      Author: hp
 */

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


class Task{
private:
	int priority;
public:
	Task(const int priority) : priority(priority)
	{

	}
	bool operator<(const Task& other)
	{
		if(priority < other.priority)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& out, const Task& other);
	int& getPriority()
	{
		return priority;
	}
};

ostream& operator<<(ostream& out, const Task& other)
{
	out << other.priority;
	return out;
}

class Container{
private:
	std::vector<Task> vec;
public:
	Container& operator<<(const Task task)
	{
		vec.push_back(task);
		return *this;
	}

	void printMin()
	{
		Task minn = vec[0];
		for(int i = 1 ; i < vec.size(); i++)
		{
			if(vec[i] < minn)
				minn = vec[i];
		}
		cout << "Min value in vector is " << minn << endl;
	}
	int& operator[] (int index)
	{
		if(index < vec.size())
			return vec[index].getPriority();
	}
};

class MyString{
private:
	int size;
	char* literals;
	friend std::ostream& operator<<(std::ostream& out, const MyString& other);
public:
	MyString()
	: literals(nullptr), size(0)
	{
		cout << "Default Constructor called." << endl;
	}
	MyString(const char* inputLiterals)
	: size(strlen(inputLiterals)), literals(new char[size+1])
	{
		memcpy(literals, inputLiterals, size);
		literals[size] = '\0';
		cout << "Parameterized Constructor called" << endl;
	}

	MyString(const MyString& other)
	: size(other.size),
	  literals(new char[size+1]) // Deep Copying - Step 1
	{
		// Copy Ctor --> Data Init --> Mmember Init. List
		memcpy(literals, other.literals, size); // Deep Copying - Step 2
		literals[size] = '\0';
		cout << "Copy Constructor called." << endl;
	}


	void print()
	{
		if(literals != nullptr)
		{
			cout << literals << endl;
		}
	}
	int getSize() const
	{
		return size;
	}
	void setLiterals(const char* str)
	{

		int newSize(strlen(str));
		if(newSize > size)
		{
			//throw exception
			//return error
		}
		else
		{
			memset(literals, 0, size);
			memcpy(literals, str, newSize);
			size = newSize;
			literals[size] = '\0';
		}
	}
	MyString operator+ (const MyString& other)
	{
		cout << "Operator+ Overloading is called" << endl;
		char* newLiterals = new char[size + other.size]; // anything dynamically allocated should be deleted
		//         newlLiterals
		// <---------------------------->
		// <-- hello --> <-- world --> <-- 0 -->
		memcpy(newLiterals, literals, size);
		memcpy(&(newLiterals[size]), other.literals, other.size);
		newLiterals[size + other.size] = '\0';
		MyString newObject(newLiterals);
		delete[] newLiterals;
		return newObject;
	}

	MyString operator+(const char age)
	{
		cout << "Operator+int called. " << endl;
		char* newLiterals = new char[size+1+1];
		memcpy(newLiterals, literals, size);
		newLiterals[size] = age;
		newLiterals[size+1] = '\0';

		MyString newObject(newLiterals);
		delete[] newLiterals;
		return newObject;
	}
	MyString& operator=(const MyString& other)
	{
		if(this == &other)
		{
			return *this;
		}
		if(literals != nullptr)
		{
			delete[] literals;
		}
		literals = new char[other.size+1];
		memcpy(literals,other.literals,other.size);
		size = other.size;
		literals[size]= '\0';
		cout << "Copy Assignment Operator is called." << endl;
		return *this;
	}

	friend ostream& operator<<(ostream& out, MyString& other);

	~MyString()
	{
		cout << "Destructor is called." << endl;
		delete [] literals;
		literals = nullptr;
		size = 0;
	}
};

ostream& operator<<(ostream& out, MyString& other)
{
	out << other.literals;
	return out;
}

class Employee{
private:
	string ID;
	string name;
	int age;
public:
	Employee(const string&& ID, const string&& name, const int age)
	: ID(ID), name(name), age(age){

	}

	void printInfo()
	{
		cout << "Name: " << name << " - ID: " << ID << " - Age: " << age << endl;
	}

	void setAge(int age)
	{
		this->age = age;
	}
	void setId(int id)
	{
		this->ID = id;
	}
	void setName(string name)
	{
		this->name = name;
	}
};

class Database{
public:
	void read()
	{

	}
	void write()
	{

	}
};

class Dummy{
Database database;
public:
	void func()
	{
		database.read();
		database.write();
	}
};

class DataRetreiver{
private:
	Database database;
public:
	Database getDatabase() const
	{
		return database;
	}
};

class Doer : public Employee
{
private:
	vector<int>issues;
public:
	void writeCode()
	{

	}
};
class TeamLeader : public Employee
{
private:
	string teamName;
public:
	TeamLeader() : Employee("777", "Jana", 23)
	{

	}
	void func()
	{
		teamName = "embedded";
		setName("jana");
	}
	void reviewCode(const Doer& doer)
	{

	}
};

class Base{
	int num;
public:
	Base()
	: num(0)
	{
		cout << "Base Default Constructor called." << endl;
	}
	~Base()
	{
		cout << "Base Destructor called." << endl;
	}
};

class Child{
public:
	Child()
	{
		cout << "Child Constructor called" << endl;
	}
	~Child()
	{
		cout << "Child Destructors called" << endl;
	}
};

class Level1{
public:
	int var = 0x11;
};

class Level2: public Level1
{
public:
	int var = 0x22;

};
int main()
{
	/*Task t1(1);
	Task t2(2);
	Task t3(3);
	Container c1;
	c1 << t1 << t2 << t3;
	c1.printMin();
	c1[2] = 10;
	cout << c1[2];*/
//	MyString name("jana"); //Copy Ctor
//	MyString name2(name); //Copy Ctor
//	MyString name3;
//	name3 = name; // Copy Assignment Operator name3.operator=(name)
//	name2 = name3;
//	cout << name2 << endl;
//	name = name2 = name3;
	Child childObject;
	cout << "Hello" << endl;
	Level2 obj;
	obj.Level1::var = 0xAA;

}


