#!/bin/bash

nasm -f elf64 syscall.S -o syscall.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles MT26145_q4.cpp -o q4.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles basicIO.cpp -o basicIO.o

ld -o q4 syscall.o q4.o basicIO.o

rm -f syscall.o q4.o basicIO.o
