/*
 * main.cpp
 *
 *  Created on: Jul 15, 2025
 *      Author: Jana Wael
 */
#include <iostream>
#include <string.h>
using namespace std;

/*
#include "DatabaseAccess.h"
#include "Viewer.h"
*/
class MyString{
private:
    int size;
    char* literals;
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
    friend std::ostream& operator<<(std::ostream& out, const MyString& other);
    ~MyString()
    {
        cout << "Destructor is called." << endl;
        delete [] literals;
        literals = nullptr;
        size = 0;
    }
};

enum Order {
	FIRST,
	SECOND
};
void print(char* value)
{
	cout << "Char* called" << endl;
}

void print(int value)
{
	cout << "Int called" << endl;
}

void add(int x)
{

}

void add(double x)
{

}

class Dummy2{
	int num = 10;
public:
	int getNum()
	{
		return num;
	}
};

class Dummy1{
	int num = 10;
public:
	int operator+(Dummy2& ob)
	{
		return ob.getNum() + num;
	}
};

std::ostream& operator<<(std::ostream& out, const MyString& other)
{
	//Exact match for a predefined function
	out << other.literals;
	return out;
}

int main()
{
	//add((float)(5.5));

	/*print(0);
	print("j");
	print(FIRST);*/
	/*MyString hello("Hello");
	MyString world("World");
	MyString helloWorld = hello + world;*/
	/*MyString name("Jana");
	int age = 65;
	MyString combinedInfo = name + age; //name.oeprator(age)
	combinedInfo.print();*/
	Dummy1 ob1;
	Dummy2 ob2;
	cout << ob1+ob2 << endl;

	MyString name = "jana";
	MyString age = "23";

	//Not exact match/ Conversion
	//1.Exact 2.Implicit Casting 3.Conversion with user-defined function
	cout << name;
	cout << name << age << endl; // call chaining in cout
	//std::ostream cout;
	std::cout << name; //cout.operator<<(name) --> this means we should override the operator<< in cout class!
	//If no print function is defined where it takes an enum, then the compiler implicitly casts the enum to integers
}
