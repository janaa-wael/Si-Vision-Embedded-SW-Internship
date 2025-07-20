# Session 6 Notes

- When calling copy constructor, default constructor of the base class is also called.

- Special member functions aren't inherited (e.g.: constructors, assignment operators, etc.)

- Child could use data members or methods from the parent or use objects of the parent class, but the reverse shouldn't happen, because parents shouldn't know about their children because this defies the target of inheritance

- In this example Level3 couldn't access var1 & var2 because Level2 inherits all Level1's data members and methods privately!

  ![image-20250720025538516](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720025538516.png)

- The derived class can change the access level of inherited members.

- For example, if a child class inherits the base class publicly, the protected functions, like print(), remain protected in the child class, therefore, no external object can access these protected functions.

- We can change the inherited data access level using the keyword ***using*** in the public section as follows:

  ![image-20250720025805319](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720025805319.png)

- Multiple Inheritance enables a derived clas to inherit members from more than one parent! *(Not Recommended)*

- It's usually not preferred as it causes the "Diamond" problem, as shown in the figure:

  ![image-20250720033936497](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720033936497.png)

- It's usually advised to avoid multiple inheritance, unless we are working with abstracts.

- Example of Diamond Problem Design:

  ![image-20250720034848825](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720034848825.png)

  > > Solution: We can determine which role we're accessing using scope operator
  > >
  > > ![image-20250720034952619](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720034952619.png)

- Different type of casting:

  1- static_cast<TYPE>(object)

  	- Normal conversion between types, conversions that rely on static (compile-time) type information.
  	- Casts between numeric types (From short to int or from into to float)
  	- Casts through inheritance hierarchies either upward or downward. Upward casting is always unnecessary.
  	- Performs compile-time checks and has no run time overhead.

  2- dynamic_cast<TYPE>(object)

  3- reinterpret_cast<TYPE>(object)

  4- const_cast<TYPE>(object)

- Casting from child to parent >> Upward casting (not necessary)

  - We can only access the base data members and methods

- Casting from parent to child >> Downward casting

- We can construct a parent class from a child class by copying the base properties of the childObject to the parent Object.

  ![image-20250720111552166](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720111552166.png)

- We can override parent methods in child method.

  e.g.:

   ![image-20250720111424817](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720111424817.png)

- Assert:

  - `assert(0)` is a macro in C (from `<assert.h>`) that causes the program to **terminate immediately with an assertion failure**.

  - `assert(expression)` checks if `expression` is true (non-zero).

  - If the expression is false (zero), the program prints an error message and calls `abort()`, which terminates the program.

  - Many bugs occur if the else isn't implemented.

- REMEMBER: Parent class shouldn't know anything about its children because this is considered a bad design.

  ![image-20250720115857318](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720115857318.png)

- Reference objects are like reference variables, their data is accessed using dot operator.

- What's the output of this code?

  ![image-20250720122755413](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720122755413.png)

  > > Solution: Base is printed when calling getName method because name member in it is used to access the name data member in Base Class & not Child class!

- What's the output of this code?
  ![image-20250720123029269](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720123029269.png)

> Child is printed because child class overrides the getName of Parent.

- What is the output of this code?

  ![image-20250720123302210](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720123302210.png)

> Solution: Child >> Base >> Base.
> The type of the object/ref variable/pointer object determines which method will be called. 

- **Polymorphism:**

  - poly: means many

  - morph: means shape

  - It means many forms, hence, a polymorphic object is an object that exhibits many shapes & forms.

  - Types of Polymorphism:

    ​	1- Compile-Time Polymorphism

    - Parametric Polymorphism [Function Templates]

    - Ad-hoc Polymorphism [Function Overloading]

      2- Run-Time Polymorphism (Virtual Function)

- **Importance of Virtual Functions:**

  - The `virtual` keyword is used in C++ to enable **polymorphism** — specifically **runtime (dynamic) dispatch** of function calls through base class pointers or references.

  - Purpose: To allow **derived classes** to **override** methods of base classes and ensure the correct method is called at runtime, even when accessed via a base class pointer.

  - Virtual function is a member function which is declared within a base class and is overridden by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.

  - They're mainly used to achieve Runtime Polymorphism

  - A **virtual pointer** (commonly known as `vptr`) is a **hidden compiler-generated pointer** used to implement **runtime polymorphism** in C++.

  - It works **behind the scenes** when you use **virtual functions** in a class.

  - *How it works?*

    When a class contains **at least one virtual function**, the compiler:

    1. Creates a **virtual table** (called **vtable**) — a lookup table of function pointers for all virtual functions.
    2. Adds a **hidden pointer** inside each object of that class, called the **vptr**.
    3. At **object construction**, the `vptr` is set to point to the class’s vtable.
    4. When a virtual function is called via a base pointer/reference, the function is looked up via the `vptr`.

  - Virtual isn't written beside the child's function prototype, if there're no granadchildren who want to override it again.

  - You can't access vptr directly, it's managed by the compiler.

  - Every polymorphic object (with virtual functions) has one vptr.

  - vptr gets updated if you change the actual type of the object during inheritance.

    ![image-20250720154535036](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720154535036.png)

  - `reinterpret_cast` is a **type of cast** in C++ used to convert **any pointer type to any other pointer type**, or even between pointer and integer types.

    ![image-20250720154706415](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720154706415.png)

  - Size of the class increases by declaring virtual functions

  - Virtual Pointer is allocated in the heap (expensive operation)

    ​	1- wastes memory

    ​	2- affects the speed

  - Virtual Table is stored in the text segment.

- Question: Can a function be declared as static and virtual?

  > No, because virtual functions need this pointer while static methods can't use them!

- Virtual tables are also called "Dispatch Tables" or "Virtual Method Table" or "Vtable"

- The virtual table and virtual pointers are constructed at the beginning of the object's constructor. Therefore, it's not advisable at all to call any virtual function inside the constructor as the vpointer and vtable could be not constructed yet.

- Can a virtual function be called in the base constructor? No, it will always resolve to the base class version of the function, because the derived portion, vpointer and vtable of the class will already have been destroyed.

  