# Session 7 Notes

- Overriding Rules:

  1- the function in the child class should have the same name.

  2- The function in the child class should have the same number of args and same types as well.

  3- The function in the child class should have the same const-ness.

  4- The function in the child class should have the same return type.

  5- The function in the child class should have the same reference qualifier.

- C++ introduces a new keywrod "override", which ckecs on the above rules when the function is declared virtual and produces a compile-time error when one of the rules are violated or the base or derived function is not virtual

- **Reference qualifiers** allow you to define **different behavior** for member functions based on whether they are called on **lvalues** or **rvalues** (i.e., `obj` vs. `std::move(obj)`).
  e.g.: 

  ![image-20250720163733105](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720163733105.png)

  ![image-20250720164330177](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720164330177.png)

  ***Called only on lvalues

  ***Called only on rvalues

- We can call the function in the base clas instead of that of the overridden child class using scope operator.

  ![image-20250720164558538](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720164558538.png)

- A virtual destructor is a destructor declared with the `virtual` keyword to ensure proper cleanup when deleting a derived object through a base class pointer.
  e.g.: 

  ![image-20250720170626857](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720170626857.png)
  If the destructor isn't virtual, only the base object is deleted without the child object! which leads to *Incomplete Destruction,resource leaks and undefined behavior.*

- However, with virtual destructors, both derived and base destructors are called!

  ```c
  Base* ptr = new Derived();
  delete ptr; 
  ```

- Functions that don't make any sense in the Parent class shouldn't be implemented.
- Constructing objects from Parent classes should be prohibited, especially when declaring base classes that are meant to be incomplete or abstract, not meant to be instantiated directly
- Solution: **USE INTERFACE CLASSES**
- Interface class is a class that contains **PURE VIRTUAL FUNCTIONS** **<u>ONLY</u>**.
- Any class that has **<u>AT LEAST</u>** one pure virtual function can't be constructed.
- Pure Virtual Functions **must be** implemented by concrete child classes, otherwise the child class can't be instantiated and will remain **abstract**.
- Abstract Class: is a class that contains some pure virtual functions, and can contain other implemented methods.
- Concrete: A child class that implements all functions from the parent class.
- Interface classes in C++ **can have constructors**, but you cannot create instances of the interface class directly, it's still abstract.
  - Constructors are used, even though it contains pure virtual functions, in order to initialize data members
  - They're called via the child constructors

- Single Responsility Principle states that:

  > **A class (or function/module)** should do **only one thing**, and **do it well**.

- Factory Design Pattern: is a **creational design pattern** used in object-oriented programming to **create objects** without specifying the **exact class of the object** that will be created.
- What is the output of line 2?![image-20250720221302100](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250720221302100.png)

> Expectations: It should because this is wrong casting, I2C class contains methods that aren't implemented in SPI class.
>
> Results: Successful Compilation!
> because static_cast does compile-time checks, no run-time checks because virtual functions result in the creation of virtual pointer and virtual tables during **runtime**, so the compiler won't be able to detect this error.
>
> Solution: Use dynamic_cast which does run-time checks and returns nullptr if casting is wrong

- `dynamic_cast` 

  - does run-time checks (overhead) which increase the execution time and thus decreases the speed. We resort to run-time because there's information that cannot be accessed during compile-time.

  - It fails when:

    1- The returned object is not a child of the object to-be casted.
    2- No virtual functions are declared.
    3- With protected or private inheritance.

  - only works on <u>pointers & references</u>, no copies.

    ​	e.g.:

    ```c
    SPI& spi1 = dynamic_cast<SPI&>(protocolBase); //reference object
    SPI* spi2 = dynamic_cast<SPI*>(protocolBase); //pointer
    ```

  - If dynamic casting fails & the object is casted to a derived object ptr, nullptr is returned.

    ```c
    SPI* spi2 = dynamic_cast<SPI*>(protocolBase); //pointer
    if(spi2 == nullptr)
    {
    	cout << "Bad Casting" << endl;
    }
    ```

  - If the object is casted to a derived object reference, it will throw std::bad_cast exception.

    ```
    try
    {
    	SPI& spi1 = dynamic_cast<SPI&>(protocolBase); //reference object	
    }
    catch(std::bad_cast& exception)
    {
    	assert(0);
    }
    ```

     

- RTTI: Run-Time Type Information

  > **RTTI** allows the **type of an object to be determined during program execution**, rather than at compile time.

- Meta-data: Information about data / data about the data

- Object Slicing: 

  - refers to the assigning of a Derived class object toa Base class object.
  - when a derived object is copied to a base class, the virtual pointer isn't copied, hence, even the derived object overrides the virtual function, the base object has no reference to the virtual table.
  - This is common when passing objects in function and storing objects in containers.