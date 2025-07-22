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

  - Syntax: 

    template <typename T1, typename T2>

  - They are functions that serve as a pattern for creating other similar functions. It is a feature to create a function without having to specify the exact type(s) of some or all of the variables. Instead, we define the function using placeholder types, called **template type parameters**.

    e.g.: Instead of creating:

    ```c
    int add (int a, int b);
    float add(float a, float b);
    char add(char a, char b);
    ```
  
    We create template function as follows:
  
    ```c
    template <typename T>
    T add(T a, T b);
    ```

  - `Template` keyword is used to define that the given entity is a template and `typename` keyword is used to define template parameters which are nothing but types that will be provided when an instance is created.

  - The keyword `typename` can be replace with the keyword `class`.

    ![image-20250721113927678](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250721113927678.png)
  
  - If we need to decouple the return type from the arguments' types & we call the function without specifying the return type at compile-time, compilation error occurs. We should **explicitly** specify the return type at compilation time because the compiler won't be able to deduce it, since R is declared as a separate template parameters with no linkage to T1 or T2.
  
    ```c
    template <typename T1, typename T2, typename R>
    R add(T1 a, T2 b)
    {
        return a+b;
    }
    ```
  
  - There can be default types to the template types, in which case it's fine not to explicitly specify the return type at compilation time.
  
    e.g.: 
  
    ![image-20250721044525976](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250721044525976.png)
  
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
  
  - Templates are **not actual code** until they're instantiated with a specific type. If the **template definitions** are in a `.cpp` file, the compiler **doesn't generate code** for the specific type unless the full definition is visible at compile time.
  
  - SIMD instructions:
  
    - The acronym **SIMD** stands for **Single Instruction, Multiple Data**. It's a form of parallelism at the instruction level. Instead of processing one piece of data at a time (like traditional scalar instructions), SIMD instructions load multiple data elements into a special, wider register and then apply the same operation to all of them in one go.
    - Imagine you have a list of numbers, and you want to add 5 to each one.
      - **Without SIMD:** You'd load the first number, add 5, store the result. Then load the second number, add 5, store, and so on. This is a sequential process.
      - **With SIMD:** You could load, say, four numbers into a single SIMD register. Then, a single SIMD "add" instruction would add 5 to all four numbers simultaneously. The results would then be stored back. This dramatically reduces the number of instructions and clock cycles required.