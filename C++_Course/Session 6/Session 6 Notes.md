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