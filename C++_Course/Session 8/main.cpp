/*
 * main.cpp
 *
 *  Created on: Jul 21, 2025
 *      Author: hp
 */
#include <iostream>
#include <string>
using namespace std;

// Functor: Overloading operator()
class Functor {
public:
    bool operator()(const int num1, const int num2) {
        cout << "Operator () successfully overloaded!" << endl;
        return num1 < num2;
    }
};

// Generic add function using template
template <typename T>
T add(const T& ob1, const T& ob2) {
    return ob1 + ob2;
}

// Template class Container
template <typename Type>
class Container {
private:
    Type* arr;
    int size;
    int emptyLocation;
public:
    Container(const int size);

    void addElement(const Type num);

    ~Container() {
        if (arr != nullptr) {
            delete[] arr;
        }
    }
};

// Constructor
template <typename Type>
Container<Type>::Container(const int size)
    : arr(new Type[size]), size(size), emptyLocation(0)
{
}

// addElement method
template <typename Type>
void Container<Type>::addElement(const Type num) {
    if (emptyLocation < size) {
        arr[emptyLocation++] = num;
    } else {
        cout << "Container is full!" << endl;
    }
}

int main() {
    // Functor usage
    Functor ob;
    bool output = ob(10, 20);
    cout << "Comparison result: " << output << endl;

    // Template add function usage
    cout << "Add (int): " << add(10, 10) << endl;
    cout << "Add (double): " << add(20.1, 20.2) << endl;
    cout << "Add (string): " << add(string("Hi "), string("Hello")) << endl;

    // Container usage
    Container<int> cont1(10);
    cont1.addElement(10);
    cont1.addElement(20);
    cont1.addElement(30);
    cont1.addElement(40);
}
