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
   `MT26145_build_q2.sh`. The program is built by running this shell script,
   which compiles the C++ source without the standard libraries and removes
   the temporary object file.

3. **Q3 - Name, Age and Confirmation**  
   In this part, the program was extended to take the user's name and age
   and ask for confirmation using `y` or `n`. This was done using the
   provided `basicIO` functions and the NASM `syscall.S` file without using
   standard C/C++ libraries. The program was implemented in
   `MT26145_q3.cpp`, with the compilation commands in
   `MT26145_build_q3.sh`. The program is built by running this shell script,
   which assembles `syscall.S`, compiles the C++ source without standard
   libraries, links the files, and removes temporary object files.

4. **Q4 - Dynamic Allocation of Names**  
   In this part, the program was extended to determine the number of names
   required and allocate memory for them. Dynamic memory allocation was
   performed using `mmap`, with 100 bytes allocated for each name to prevent
   overflow. The implementation was done in `MT26145_q4.cpp`, with the
   compilation commands provided in `MT26145_build_q4.sh`. The program is
   built by running this shell script, which assembles the system-call file,
   compiles the C++ source without standard libraries, links the program,
   and removes temporary object files.

5. **Q5 - Changing the Number of Names**  
   In this part, the program was extended to allow the number of names to
   be changed after the initial input. The code was implemented in
   `MT26145_q5.cpp`, with the compilation commands provided in
   `MT26145_build_q5.sh`. The program is built by running this shell script,
   which assembles the system-call file, compiles the C++ source without
   standard libraries, links the program, and removes temporary object files.

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

Prompts:
"Explain the g++ compilation options required to compile a C++ program without using the standard C/C++ libraries"

"Help me create a shell script for compiling the Q2 C++ program using the required g++ options."
### Q3

LLM was used to understand how the provided `basicIO` functions and NASM
`syscall.S` file work together and to debug compilation and linking
issues. The main challenge was connecting the C++ program with the
provided assembly system-call implementation while avoiding standard
C/C++ libraries.

Prompts:
"Explain how the provided basicIO.cpp, basicIO.h and syscall.S files work together and 
how I can write the Q3 C++ program without using standard C/C++ libraries."

"Help me implement the Q3 requirements for taking the user's name and age, validating the input, asking for y/n confirmation."

### Q4

LLM was used to implement dynamic allocation for the required number of
names and to review input validation and buffer-overflow prevention in
`MT26145_q4.cpp` and `MT26145_build_q4.sh`. We encountered compilation
and linker issues while building the program with direct system calls,
which were resolved during development.

Prompts:
"Explain how to implement Q4 so that the program first takes the number of names, 
dynamically allocates memory for that many names, and prevents buffer overflow without using standard libraries."


"Review the Q4 implementation and ensure that it uses a C++ class, object, and C++ operators as required by the assignment."

### Q5

LLM was used to extend the Q4 implementation so that the number of names
could be changed after the initial input in `MT26145_q5.cpp` and
`MT26145_build_q5.sh`. The main challenge was handling both increasing
and decreasing the number of names while preserving existing names,
allocating the required new memory, adding new names when necessary,
and correctly releasing the old memory.

Prompts:
"Help me extend Q4 for Q5 so that the user can change the number of names after entering the initial names, 
while preserving existing names and adding or removing names as required."

"Help me validate the Q5 input, including invalid number-of-names input and invalid y/n responses, without using standard C/C++ libraries."

Prompts:

"Review the compilation, linking, memory allocation, input validation, 
and buffer overflow handling of the assignment programs and help identify and fix errors."

Overall, LLM assistance was used as a development and debugging aid.
The implementations were manually tested and verified before being
committed to the Git repository.
