#!/bin/bash

cmake .
make -j4
#make -j4 1>succ.txt 2>fail.txt
#cat succ.txt
#cat fail.txt

cd build/
./DesignPattern


