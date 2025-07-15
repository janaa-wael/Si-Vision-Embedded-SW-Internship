/*
 * main.cpp
 *
 *  Created on: Jul 15, 2025
 *      Author: Jana Wael
 */
#include <iostream>
using namespace std;

#include "DatabaseAccess.h"
#include "Viewer.h"

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

int main()
{
	print(0);
	print("j");
	print(FIRST);
	//If no print function is defined where it takes an enum, then the compiler implicitly casts the enum to integers
}
