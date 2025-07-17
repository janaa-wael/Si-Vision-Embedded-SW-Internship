# Session 5 Notes:

- Copy Assignment Operator Overloading is what get called when you do this:

  ![image-20250717155629433](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250717155629433.png)

  - Steps:

    1- Self-assignment check (if i'm assigning the object to itself, we shouldn't waste execution time by copying)

    ```
    if(this == &other)
    	return *this;
    ```

    2- Clean up the current resources (using delete function)

    ```
    if(literals != nullptr)
    {
    	delete[] literals;
    }
    ```

    3- Copy values from the source object (using Deep Copy Technique)

    ```
    literals = new char[other.size+1];
    memcpy(literals,other.literals,other.size);
    size = other.size;
    literals[size]= '\0';
    ```

    4- Return *this

    5- Function Signature:

    ```
    MyString& operator=(const MyString& other)  
    ```

    - **We return object of the class by reference to support call chaining as in the following line:

      ```
      MyString& operator=(const MyString& other)
      ```

- The compiler automatically generates a default destructor, a default copy constructor and a default assignment operator. If a class defines one or more of the previous functions, it should explicitly define all of them.

  <u>***Why?***</u> if one of the three functions is user-defined, it'll probably involve working with expensive resources like heap allocation. When heap allocation is involved, the default copy constructors and assignment operators will do **shallow copying** which will cause errors on destruction and the default destructor will not free the allocated resources.

- This rule is only a programmer-guide rule. The C++ doesn't enfore compilers to follow the rule of three.

- 