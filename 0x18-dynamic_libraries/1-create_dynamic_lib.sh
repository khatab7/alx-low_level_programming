#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -c -fPIC *.c
gcc -shared -o liball.c *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
