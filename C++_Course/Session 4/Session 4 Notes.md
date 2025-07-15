# Session 4 Notes

- Circular Referencing: 

  - occurs when 2 header files include each other

  - only include what you really need

    | DatabaseAccess Class                                         | Viewer Class                                                 |
    | ------------------------------------------------------------ | ------------------------------------------------------------ |
    | ![image-20250715145139808](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715145139808.png) | ![image-20250715145114787](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250715145114787.png) |

  - Ideal method: **Forward Declaration**
  - Don't occur in cpp files as they aren't included.

- ## Friends

  - Friendship isn't mutual. --> If class B is friend to class A, this doesn't mean that class A is friend to class A.

  - Friendship isn't inherited.

  - Friends aren't affected by access specifiers.

  - Friends are non-members, thus they can't use "this" pointer.

  - A friend function can be defined inside or outside a class.

  ## Function Overloading:

  - allows the creation of multiple methods (different versions) with the same name

  - Overloaded functions must have difference arguments number

  - If the number of the input arguments are the same, the datatypes should be different

  - Overloaded Functions can have different number of arguments

  - **How it works:**

    1- C++ tries to find an exact match. This is the case where the actual argument exactly matches the parameter type of one of the overloaded functions

    `void print (char* value)`
    `void print int value`

    2- If no exact match is found, C++ tries to find a match through promotion (Implicit Casting)