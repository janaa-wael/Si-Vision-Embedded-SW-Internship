# **Session 2 Notes:**

## 1- Members

- Members are variables or functions inside a class
- Instances are variables from any class type that have certain values in the class members that are only specific to this object and not shared with other instances from the same class.
- When calling constructors, we need to initalize the class members in the member initializer list.
  *Note that:* *members must be initialized in the same order they are declared by in the class definition*
- Note: In member initializer list, we can pass arguments with the same name as  the member variables, as the compiler knows that the first variable is the data member and the second is the argument of the constructor

## 2- Access Specifiers/Modifiers

- It's used to set the accessibility of class members.
- It is responsible to set <u>restrictions</u> on class members so that they don't get directly accessed by outside functions.
- Types:
  * Public: members can be accessed from anywhere in the code
  * Private: members can be accessed only inside the class scope.
  * Protected: members can be accessed only inside the class scope and its children, but can't be accessed from anywhere in the code.

## 3- Difference between Struct and Class

- ### Struct:

  ​	![image-20250714121013969](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250714121013969.png)

  - Members are public by default.

    

- ### Class:

  ​	![image-20250714121454800](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250714121454800.png)
  
  
  
  - Members are private by default. (to achieve data hiding, abstraction and encapsulation concepts)
  - 

## 3- Setters & Getters

- They are used to set & get the private data members of a class.
- Getters are used to lock and unlock the shared data members using semaphores & mutexes.
- Getters should be const, to tell the compiler that this method *never* modifies data members. In case user attempts to modify the data member, compilation error occurs.
- ***Golden Rule: Never attempt to return a data member by reference in getter methods! (UNLESS THE SIZE OF DATA MEMBER IS TOO LARGE). This exposes the member to be modified outside the class scope which is dangerous. ***
- Setters are useful to stir an instance towards a certain scneario.
- Getters are useful to get the status of a class.

### Question: What is the output?

![image-20250714125552743](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250714125552743.png)

 - Code compiles successfully!

 - Implicit casting occurs from primitive datatype (int) to user-defined datatype (Dummy), where the parameterized constructor that takes int as argument is called!

 - C++ can perform one step implicit type cast. If the RHS matches the argument's type, the object initialization is successful.

 - This may lead to ambiguous bugs. Always use the word explicit before constructors.

 - Two-step implicit casting isn't supported! 

   e.g.: ![image-20250714130920871](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250714130920871.png)

   this is a two-step implicit casting **because** we need to convert "jana" which is an array of char to string  then convert string to Dummy! this is more than one step and this isn't supported.

   

   

   ### Question: What if multiple constructors have common code? What is the correct approach to eliminate duplicate code?

   ![image-20250714143144225](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250714143144225.png)

   Solution: 

   - Use delegating constructors!

   - `We call them in the initializer list
   - Never call 2 delegating constructors in the each other's initializer list, this leads to compilation error "Constructor delegates to itself"! 

## 4- Calculating time of function execution:

![image-20250714153939702](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250714153939702.png)

## 5- Copy Constructors:

- It's needed when we want to copy one object to another.

- Order of destruction of objects is in the reverse order of their construction.

- It solves the problem of deep copying!

- Shallow Copying: copies the address of any member pointer without any heap allocation. This will opt out an undefined behavior when the destructor is called as the pointer will be deleted twice.

- Deep Copying: allocates new space for the new copy using `new` operator and copies the contents, so the new object has its new independent copy

- Copy Constructor is expensive because it does heap copying mechanisms (not recommended, if there's another less costly operation it will be more preferrable)

- SO, if we need to pass any object as argument to  function, we should pass it by reference to prevent heap operations.

- Use this syntax: 

  `void func(const MyString& obj)`

  --> & means that the ownership of the object isn't possessed by the function *(to prevent calling the copy constructor which is expensive)*
  --> const means that this function doesn't modify anything in the object

- RVO: Return Value Optimization, it's a compiler-dependent optimization technique 

- to prevent this, use the flag: -fno-elide-constructors 

![image-20250715004008759](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715004008759.png)