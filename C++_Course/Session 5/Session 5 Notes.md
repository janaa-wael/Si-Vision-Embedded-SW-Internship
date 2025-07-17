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

- Question: What function is called?

  ```
  int main()
  {
  	MyString name4 = "hi";
  }
  ```

  1- RHS is RValue ?? Creates temp location in memory >> Parameterized Ctor

  2- Copy from temp location to name4 >> Copy Ctor

  3- Destruction of temp location

  4- Desctruction of name4

  INSTEAD, it's better to use this syntax:

  ```
  int main()
  {
  	MyString name4("hi");
  }
  ```

- ![Screenshot 2025-07-17 202644](D:\Courses\Si-Vision\Embedded SW Internship\Si-Vision-Embedded-SW-Internship\C++_Course\Session 5\Screenshot 2025-07-17 202644.png)**Inheritance:**

  ![image-20250717202806139](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250717202806139.png)

  - **Why inheritance?**

    - defines an "Is-A" relationship between the parent and the child.

    - Child classes inherit properties of the parent class (i.e.: data members, methods)

    - The ability of a class to derive properties and behavior from another class is called **Inheritance**. It introduces a new level of objects relationship called "Is-A".

    - Inheritance models real-life example using hierarchial scheme where objects carry different labels:

      1- Parent/Super/Base Class:

       - A class whose properties are inherited.

      2- Child/Derived Class:

      - A class that inherits properties from another class.

    - A class can be a parent and a derived class at the same time.