# ExpL COMPILER

This repository contains my implementation of ExpL(Experimental Language) done as part of the Compiler Laboratory course I took in 2023.

The compiler was written in C using the C lexer which is present in lex.yy.c and YACC parser which is present in the y.tab.c file.

It compiles the source language ExpL(spec [here](https://silcnitc.github.io/expl.html) and [here](https://silcnitc.github.io/oexpl-specification.html)) to the low-level XSM (eXperimental String Machine) machine code (ABI [here](https://silcnitc.github.io/abi.html)) which runs on ExpOS (Experimental Operating System) a simulator for which can be found [here](https://silcnitc.github.io/install.html#navxsm).

The project is divided into 8 incremental stages and as such, the repository has a folder which contains the state of the project at the end of each stage. The stages are as follows:

1. Arithmetic Expressions
2. Static Storage Allocation
3. Flow Control Statements
4. User Defined Variables and Arrays
5. Functions
6. User-defined Types and Dynamic Memory Allocation
7. Objects – Data Encapsulation
8. Inheritance and Sub-type Polymorphism

More details about the project can be found on the [website](https://silcnitc.github.io/).
