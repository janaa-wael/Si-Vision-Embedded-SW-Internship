# **Session 2 Notes:**

## 1- Members

- Members are variables or functions inside a class
- Instances are variables from any class type that have certain values in the class members that are only specific to this object and not shared with other instances from the same class.
- When calling constructors, we need to initalize the class members in the member initializer list.
  *Note that:* *members must be initialized in the same order they are declared by in the class definition*

## 2- Access Specifiers/Modifiers

- It's used to set the accessibility of class members.
- It is responsible to set <u>restrictions</u> on class members so that they don't get directly accessed by outside functions.
- Types:
  * Public: members can be accessed from anywhere in the code
  * Private: members can be accessed only inside the class scope.
  * Protected: members can be accessed only inside the class scope and its children, but can't be accessed from anywhere in the code.

## 3- Difference between Struct and Class

- ### Struct:

  - ![image-20250714121013969](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250714121013969.png)

  - Members are public by default.

    

- ### Class:

  - Members are private by default. (to achieve data hiding, abstraction and encapsulation concepts)
  - 