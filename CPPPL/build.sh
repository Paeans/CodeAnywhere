#!/bin/bash

cppfilelist=""
for filename in $( ls *.cpp 2> /dev/null )
do
    cppfilelist+=${filename}" "
done
[[  ${cppfilelist} == "" ]] && echo "No cpp files found" && exit 1

g++ -std=c++0x -o result.out ${cppfilelist} && [[ $1 == "n" ]] || ./result.out
