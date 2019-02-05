#!/bin/bash

g++ -std=c++14 -g -fsanitize=undefined $1".cpp" -o $1

mkdir $1"_outputs"
cd "./"$1"_inputs/"
for file in *.in; do
     echo "executando "$file
     "../"$1 < $file > "../"$1"_outputs/"$file
done
