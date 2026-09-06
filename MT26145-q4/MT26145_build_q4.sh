#!/bin/bash

# Roll No : MT26145
# Name : Soham Biswas

nasm -f elf64 syscall.S -o syscall.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables MT26145_q4.cpp -o q4.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables basicIO.cpp -o basicIO.o

g++ -nostartfiles -no-pie syscall.o q4.o basicIO.o -o q4

rm -f syscall.o q4.o basicIO.o
