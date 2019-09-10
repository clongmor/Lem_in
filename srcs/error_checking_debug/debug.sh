#!/bin/bash

DIR=maps_ko/ants/

gcc -Wall -Werror -Wextra main.c parsing.c ../../libft/libft.a -o debug

for file in $DIR*
do
    ./debug < $file
done
