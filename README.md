# Monty

# C - Stacks, Queues - LIFO, FIFO

## Leraning Objectives

What do LIFO and FIFO mean
What is a stack, and when to use it
What is a queue, and when to use it
What are the common implementations of stacks and queues
What are the most common use cases of stacks and queues
What is the proper way to use global variables
How to work with git submodules

## Requirements

### General

Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You allowed to use a maximum of one global variable
No more than 5 functions per file
You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called monty.h
Don’t forget to push your header file
All your header files should be include guarded
You are expected to do the tasks in the order shown in the project
The repository monty should be added as a submodule to your holbertonschool-low_level_programming repository, under the name 0x19-stacks_queues_lifo_fifo

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
```

## Compilation & Output

The code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### The monty program:

Usage: monty file, where file is the path to the file containing Monty byte code.
example:

```
./monty bytecodes/06.m 
```

| OPCODE | DESCRIPTION |
|------------ | --------------|
| push | pushes an element to the stack. |
| pall | prints all the values on the stack, starting from the top of the stack.|
| pint | prints the value at the top of the stack, followed by a new line.|
| pop | removes the top element of the stack. |
| swap | swaps the top two elements of the stack.|
| add | adds the top two elements of the stack. |
| nop | doesn’t do anything. |
| sub | subtracts the top element of the stack from the second top element of the stack.|
| div | divides the second top element of the stack by the top element of the stack.|
| mul | multiplies the second top element of the stack with the top element of the stack.|
| mod | computes the rest of the division of the second top element of the stack by the top element of the stack.|
| # | When the first non-space character of a line is #, treat this line as a comment (don’t do anything).|
| pchar | prints the char at the top of the stack, followed by a new line.|
| pstr | prints the string starting at the top of the stack, followed by a new line. |
| rotl | rotates the stack to the top. |
| rotr | rotates the stack to the bottom. |
| stack | sets the format of the data to a stack (LIFO). This is the default behavior of the program.|
| queue | sets the format of the data to a queue (FIFO).|
