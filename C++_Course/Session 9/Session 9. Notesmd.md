# Session 9:

- Move Constructors:

  - What will happen in this scenario?

    ```
    MyString createString()
    {
    	MyString randomString("123");
    	return randomString;
    }
    ```

    1- createString() will be called. The randomString will be created, therefore, a parameterized constructor will be called.

    2- The function returns the created string by value, therefore, a temporary location in memory will be allocated to copy the randomString to it.

    3- Now that the randomString is copied, its destructor will be called.

    4- The function has finished its duties. The temporarily allocated MyString now will be copied to newString.

    5- Since newString has captured the created string, the temporary location is no longer needed. Its destructor will be called.

  - Copy Constructors are expensive functions because they implement deep copying. in our scenario, the copy constructor:

    - allocates a new literals array (Heap Allocation)
    - copies the literals of the passed object to the literals of this object. (Copying Operation)

  - If we know that the temporary location will be destroyed, can't we steal its resources intead of copying them?

    > Yes! Using, Move Constructors we can achieve this.

- Lvalue Vs Rvalue

  - Function accepts objects by Lvalue Reference.

    ```c
    void func(Dummy& object)
    ```

  - Function accepts objects by Rvalue Reference.

    ```c
    void func(Dummy&& object); //We can pass to this function temporary objects
    ```

- Move Constructor:

  ```c
  // Move Constructor
  MyString(MyString&& other) :
  	literals(other.literals), //Stealing of Resources - Ownership Transfer
  	size(other.size)
  {
      other.size = 0;
  	other.literals = nullptr; 
      //so that when we delete this ptr, we don't delete the 
      //allocated memory it's pointing to in heap!
  }
  ```

  