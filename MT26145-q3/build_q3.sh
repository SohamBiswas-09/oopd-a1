#!/bin/bash

nasm -f elf64 syscall.S -o syscall.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles q3.cpp -o q3.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles ../src/basicIO.cpp -o basicIO.o

ld -o q3 syscall.o q3.o basicIO.o

rm -f syscall.o q3.o basicIO.o
