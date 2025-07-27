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

- 