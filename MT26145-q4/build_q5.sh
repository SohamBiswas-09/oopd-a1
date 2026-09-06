#!/bin/bash

nasm -f elf64 syscall.S -o syscall.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles MT26145_q5.cpp -o q5.o

g++ -c -nostdlib -nodefaultlibs -nostartfiles basicIO.cpp -o basicIO.o

ld -o q5 syscall.o q5.o basicIO.o

rm -f syscall.o q5.o basicIO.o
