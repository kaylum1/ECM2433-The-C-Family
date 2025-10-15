#!/bin/bash

gcc -ansi -c coursework.c -o coursework.o

gcc -ansi -c msString.c -o msString.o

gcc coursework.o msString.o -o coursework

if [ $? -ne 0 ]; then
    echo "compilation failed"
    exit 1
fi
echo "successful compilation"

exit