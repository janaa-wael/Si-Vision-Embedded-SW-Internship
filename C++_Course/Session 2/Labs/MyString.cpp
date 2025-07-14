#include <iostream>
#include <vector>
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

int main()
{
    MyString name("Jana");
    int nameSize = name.getSize();
    
}