# OOPD Assignment 1

**Roll No:** MT26145  
**Name:** Soham Biswas

This repository contains the implementation of Assignment 1 for the
Object-Oriented Programming and Design course.

## Assignment Tasks

1. **Q1 - Git Repository Setup**  
   In this part, a private GitHub repository named `oopd-a1` was created
   and a `README.md` file was added. The repository was then cloned locally
   and used throughout the assignment.

2. **Q2 - Basic C++ Program**  
   In this part, we created a C++ program named `MT26145_q2.cpp` which does
   nothing except return `0`. It was compiled using `g++` options excluding
   the standard library files. The compilation command was placed in
   `MT26145_build_q2.sh` and then pushed to Git successfully.

3. **Q3 - Name, Age and Confirmation**  
   In this part, the program was extended to take the user's name and age
   and ask for confirmation using `y` or `n`. This was done using the
   provided `basicIO` functions and the NASM `syscall.S` file without using
   standard C/C++ libraries. The program was implemented in
   `MT26145_q3.cpp`, with the compilation commands in
   `MT26145_build_q3.sh`. It was pushed to Git successfully.

4. **Q4 - Dynamic Allocation of Names**  
   In this part, the program was extended to determine the number of names
   required and allocate memory for them. Dynamic memory allocation was
   performed using `mmap`, with 100 bytes allocated for each name to prevent
   overflow. The implementation was done in `MT26145_q4.cpp`, with the
   compilation commands provided in `MT26145_build_q4.sh`.

5. **Q5 - Changing the Number of Names**  
   In this part, the program was extended to allow the number of names to
   be changed after the initial input. The code was implemented in
   `MT26145_q5.cpp`, with the compilation commands provided in
   `MT26145_build_q5.sh`.

The assignment requires the use of classes, objects and C++ operators.
Direct system calls must be used, while standard C/C++ libraries,
templates and template libraries are not allowed. Input validity checks
are also compulsory.

## LLM Use Declaration

### Q2

LLM was used to understand the required `g++` compilation options and
prepare the build command for `MT26145_q2.cpp` and
`MT26145_build_q2.sh`. The main difficulty was understanding how to
compile the program while excluding the standard libraries and startup
files. Temporary object files were also removed after compilation.

### Q3

LLM was used to understand how the provided `basicIO` functions and NASM
`syscall.S` file work together and to debug compilation and linking
issues. The main challenge was connecting the C++ program with the
provided assembly system-call implementation while avoiding standard
C/C++ libraries.

### Q4

LLM was used to implement dynamic allocation for the required number of
names and to review input validation and buffer-overflow prevention in
`MT26145_q4.cpp` and `MT26145_build_q4.sh`. We encountered compilation
and linker issues while building the program with direct system calls,
which were resolved during development.

### Q5

LLM was used to extend the Q4 implementation so that the number of names
could be changed after the initial input in `MT26145_q5.cpp` and
`MT26145_build_q5.sh`. The main challenge was handling both increasing
and decreasing the number of names while preserving existing names,
allocating the required new memory, adding new names when necessary,
and correctly releasing the old memory.

Overall, LLM assistance was used as a development and debugging aid.
The implementations were manually tested and verified before being
committed to the Git repository.
