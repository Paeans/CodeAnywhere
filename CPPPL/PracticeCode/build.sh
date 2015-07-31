#!/bin/bash

[[ "$1" == "" ]] && echo "Need Provide cpp file" && exit 1 
g++ -std=c++0x -o result.out $1 && [[ $2 == 1 ]] && ./result.out
