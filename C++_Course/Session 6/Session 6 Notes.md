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