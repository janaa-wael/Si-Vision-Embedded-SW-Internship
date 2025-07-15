#include <iostream>
#include <vector>
#include "string.h"
using namespace std;

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
            memcpy(literals, 0, size);
            memcpy(literals, str, newSize);
            size = newSize;
            literals[size] = '\0';
        }
    }
    ~MyString()
    {
        cout << "Destructor is called." << endl;
        delete [] literals;
        literals = nullptr;
        size = 0;
    }
};

struct TestStruct{
    int x;
};

class TestClass{
    int x;
};

class Dummy{
public:
Dummy()
{
    cout << "Dummy default constructor called." << endl;
}
Dummy(int i) : Dummy()
{
    cout << "Dummy constructor called with value: " << i << endl;
}
Dummy (const std::string str)
{
    cout << "Dummy constructor called with string: " << str << endl;
}
};


void func(Dummy obj)
{
    // Function implementation
}

MyString createMyString()
{
    MyString innerStr("Hello"); //Stack >> Save
    return innerStr; // Copy to temp location
}

int main()
{
    MyString numbers = createMyString(); //temp location
}


