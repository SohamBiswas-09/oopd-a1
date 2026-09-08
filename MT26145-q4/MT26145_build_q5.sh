#!/bin/bash

# Roll No : MT26145
# Name : Soham Biswas

nasm -f elf64 syscall.S -o syscall.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles \
-fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables \
MT26145_q5.cpp -o q5.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles \
-fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables \
basicIO.cpp -o basicIO.o

g++ -nostartfiles -no-pie syscall.o q5.o basicIO.o -o q5

rm -f syscall.o q5.o basicIO.o
