#!/bin/bash

# Given a program name as argument
# build all versions of a c program within the program folder
# ./build.sh prog01
for file in ../Programs/$1v*.c
do
    build=${file%.*}
    build=${build##*/}
    gcc "$file" -o "$build";
done