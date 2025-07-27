## Makefile Syntax

A Makefile consists of a set of *rules*. A rule generally looks like this:

```
targets: prerequisites
	command
	command
	command
```

- The *targets* are file names, separated by spaces. Typically, there is only one per rule.

- The *commands* are a series of steps typically used to make the target(s). These *need to start with a tab character*, not spaces.

- The *prerequisites* are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are also called *dependencies*

- If you repeat the `make` command without having any target that has its dependencies changed, the output will be `make: targetName is up to date.`

- Let's discuss this makefile:

  ![image-20250727154524351](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250727154524351.png)

  - If there's no file with the name "another" and we keep calling `make` command, it always echoes "Hello, Jana" & never prints `make: another is up to date.`

  - However, if `another` file is created, it doesn't execute the make command each time it runs. It rather prints `make: another is up to date.`

  - Rule of Thumb

    >`Make` will only rebuild a target if its dependencies are newer than the target itsefl!

  - The first rule in a Makefile is the default target.

  - Use file dependencies to control when commands run.

  - Makefiles work best when you structure your rules from smallest to largest dependencies.

    ​	1- First generate the source files if needed. (e.g.: blah.c)

    ​	2- Compile object files (e.g.: blah.o)

    ​	3- Link them into the final binary (e.g.: blah)

  - Make isn't smart, it only sees file modification times.

    > Even if a file's content doesn't change, changing its timestampe ill trigger rebuilds.

  - Rule template to follow:

    ```makefile
    final_binary: object_file
    	#link step
    
    object_file: source_file.c
    	#compile step
    
    source_file.c:
    	#optionally generate file or ensure it exists.
    ```

  - To force a command to always run, even if the target is up-to-date, use a **phony target**

    e.g.: 

    ```makefile
    .PHONY: clean
    clean: 
    	rm -f blah blah.o blah.c
    ```

  - If a target does not result in a file with the same name, `make` will always consider it out-of-date and rerun it.

  - In a Makefile, the first target is considered the default target.

  - If you run the `make` without specifying a target, it will only execute the first target & other targets will be ignored unless <u>explicitly referenced</u>.

  - `clean` is often used as a target that removes the output of other targets, but it is not a special word in Make

  - Note that `clean` is doing two new things here:

    - It's a target that is not first (the default), and not a prerequisite. That means it'll never run unless you explicitly call `make clean`
    - It's not intended to be a filename. If you happen to have a file named `clean`, this target won't run, which is not what we want. 

- Variables can only be strings. You'll typically want to use `:=`or `=`.
- Single or double quotes have no meaning to Make. They are simply characters that are assigned to the variable. Quotes *are* useful to shell/bash, though, and you need them in commands like `printf`

- To echo variables, we use the following syntax:

  ```makefile
  x := Embedded
  
  all:
  	echo $(x)
  	echo ${x}
  	#Bad practice, but works!
  	echo $x
  ```

- Making multiple targets and you want all of them to run? Make an `all` target. Since this is the first rule listed, it will run by default if `make` is called without specifying a target.

- When there are multiple targets for a rule, the commands will be run for each target. `$@` is an [automatic variable](https://makefiletutorial.com/#automatic-variables) that contains the target name.

  ```makefile
  all: f1.o f2.o
  
  f1.o f2.o:
  	echo $@
  # Equivalent to:
  # f1.o:
  #	 echo f1.o
  # f2.o:
  #	 echo f2.o
  ```

- Both `*` and `%` are called wildcards in Make, but they mean entirely different things. `*` searches your filesystem for matching filenames. I suggest that you always wrap it in the `wildcard` function, because otherwise you may fall into a common pitfall.

- `*` may be used in the target, prerequisites, or in the `wildcard` function.

  Danger: `*` may not be directly used in a variable definitions

  Danger: When `*` matches no files, it is left as it is (unless run in the `wildcard` function)

```
thing_wrong := *.o           # ❌ BAD: The string "*.o" is stored literally
thing_right := $(wildcard *.o)  # ✅ GOOD: Expands to a list of .o files at assignment time
```

```makefile
thing_wrong := *.o # Don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

all: one two three four

# Fails, because $(thing_wrong) is the string "*.o"
one: $(thing_wrong)

# Stays as *.o if there are no files that match this pattern :(
two: *.o 

# Works as you would expect! In this case, it does nothing.
three: $(thing_right)

# Same as rule three
```

- Automatic Variables:

  ```
  hey: one two
  	# Outputs "hey", since this is the target name
  	echo $@
  
  	# Outputs all prerequisites newer than the target
  	echo $?
  
  	# Outputs all prerequisites
  	echo $^
  
  	# Outputs the first prerequisite
  	echo $<
  
  	touch hey
  
  one:
  	touch one
  
  two:
  	touch two
  
  clean:
  	rm -f hey one two
  ```

- Compiling a C program: 

  `n.o` is made automatically from `n.c` with a command of the form 

  >  `$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@`

- Compiling a C++ program:

  `n.o` is made automatically from `n.cpp` or `n.cc` with a command of the form 

  > `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@`

- Linking a single object file: 

  `n` is made automatically from `n.o` by running the command 

  > `$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@`

- The important variables used by implicit rules are:

  - `CC`: Program for compiling C programs; default `cc`

  - `CXX`: Program for compiling C++ programs; default `g++`

  - `CFLAGS`: Extra flags to give to the C compiler

  - `CXXFLAGS`: Extra flags to give to the C++ compiler

  - `CPPFLAGS`: Extra flags to give to the C preprocessor

  - `LDFLAGS`: Extra flags to give to compilers when they are supposed to invoke the linker

    

    ```makefile
    $(objects): %.o: %.c
    	$(CC) -c $^ -o $@
    ```

  - This is a **static pattern rule**. It means:

    > For each object file in `$(objects)` (like `foo.o`), compile it from a matching `.c` file (like `foo.c`).

    - `%.o`: matches any object file like `foo.o`, `bar.o`
    - The **stem** is the part before `.o`, like `foo`, `bar`, `all`
    - `%.c`: turns into `foo.c`, `bar.c`, `all.c`

