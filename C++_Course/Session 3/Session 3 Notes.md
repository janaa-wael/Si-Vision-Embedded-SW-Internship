# Session 3 Notes

- When calling any function, its parameters are pushed into the stack.
- Prologue is the assembly section that is executed before the functions begins its execution.
- ![image-20250715013648627](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715013648627.png)

- This is a pointer to the object, that is, it stores its address in memory. 

- The address of object is passed as an argument to 

- When calling member methods, arguments are pushed to the stack in addition to the address of the object in the memory (which we access using this pointer)

  ![image-20250715025017925](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715025017925.png)

​	![image-20250715030132961](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715030132961.png)

- This operator helps each instance to keep track of its member variables and functions, by pointing to the first memory location of the instance.

- "This" is a constant pointer where you can the values of the underlying object it points to, but you can't make it point to something else.

- "this" pointer is implicitly added to any non-static member fucntion/

  **`e.g.: simple.setID(2); --> setID(&simple, 2);`** 

- We can use "Call Chaining" in C++ to prevent multiple consequent line calls to the methods of a certain object in the following syntax:

  ![image-20250715115125360](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715115125360.png)

- Instead, we can use call chaining in the following syntax: 

  ![image-20250715115200527](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715115200527.png)

  Under the condition that each method either returns the object itself or a pointer to it.

- sizeof(ptr) --> depends on the size of the address bus of the machine.

- In this example: what is the sizeof an object of dummy?

  ![image-20250715114504978](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715114504978.png)

Solution: 

- size is 16 bytes, not 12 due to alignment where 4 bytes of padding is added next to the 4 bytes of variable firstEmpty
  e.g.: &firstempty --> 0xAABBCCDD11223344 --> 4 bytes of firstEmpty + 4 bytes of padding

| 0xAABBCCDD11223344 | 4 bytes of firstEmpty | 4 bytes of padding               |
| ------------------ | --------------------- | -------------------------------- |
| 0xAABBCCDD1122334C | 8 bytes of arr ptr    | -------------------------------- |

- Note: size of arr ptr is independent of the datatype it's pointing to.

- Static Data Members Variables: 

  - are data members that aren't tied to a certain instance of an object, they are, however, tied to the whole class.

  - Thus, they aren't allocated in the stack of func(), since they retain their values across multiple instances.

  - It's not created in memory with the first object instantiated! 

  - They can be initialized only at its definition, not in the memory initializer list. If you attempt to do this, compilation error occurs because this member isn't stored in the memory space of the object in memory, it's stored elsewhere!

    ![image-20250715120201663](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715120201663.png)

    ![image-20250715120233316](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715120233316.png)

  - Non-static member variables are declared & defined when creating an object. However, static members aren't tied to a certain object or instance, they are tied to a class, so they should be defined outside (& declared inside the class), so that the compiler doesn't throw a compilation error when it sees the static member variable used in the code!

    ![image-20250715121035792](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715121035792.png)

- Ways to define the class:

  1- Define the class in a shared file

  2- Create a header file and define the class there

  3- Create a header file file and a source file

- Multiple declarations of the same variable or functions are valid, but multiple definitions aren't valid!

- Static Methods: are functions of a class that can be called without the need of instantiating an object from the class.