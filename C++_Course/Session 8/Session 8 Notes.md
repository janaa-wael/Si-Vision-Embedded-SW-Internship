# Session 8 Notes

- What are the callable entities in C++?

  1- Functions
  2- Lambdas (C++11)
  3- Functors: They are objects that can be used like functions. In C++, a functor is any object that overloads the function call operator `operator()`.
  ![image-20250721014756662](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250721014756662.png)

  - How many arguments should the function take?

    > Ideal Case: Functions shouldn't take any arguments. 
    >
    > *The smaller the number of args, the better.*

-  Templates:

  - They are functions that serve as a pattern for creating other similar functions. It is a feature to create a function without having to specify the exact type(s) of some or all of the variables. Instead, we define the function using placeholder types, called **template type parameters**.

  - Template functions are usually the way to go when the function's implementation doesn't differ from one type to another.

  - Normally, the template functions can deduce the type automatically.

  - Will this code compile?

    ```c
    template <typename T>
    void func(T x)
    {
    	cout << "Template" << endl;
    }
    void func(int x)
    {
    	cout << "Non Template" << endl;
    }
    func(10);
    ```

    > Solution: The code compiles, because the compiler finds the exact match of the func(int x), so Non Template is printed.

    - Question: What's the output of this code?

      ```c
      template <typename T>
      void func(T x)
      {
          cout << "Value - Template" << endl;
      }
      
      template <typename T>
      void func(T& x)
      {
          cout << "Reference - Template" << endl;
      }
      
      int main()
      {
          int x = 10;
          func(x);
          func(10);
      }
      ```

      > Solution: Compilation error occurs, because there are 2 possible matches for this function so the compiler can't know what template to use in which function. 

  - We can specify multiple template types. The compiler will implicitly deduce the types based on the passed arguments on calling. You can specify the types explicitly as follows:

    ![image-20250721044525976](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250721044525976.png)

  - Templates are **not actual code** until they're instantiated with a specific type. If the **template definitions** are in a `.cpp` file, the compiler **doesn't generate code** for the specific type unless the full definition is visible at compile time.