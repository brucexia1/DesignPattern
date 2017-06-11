#!/bin/bash
basepath=$(cd `dirname $0`; pwd)


#build 3rdlib
cd basepath/3rdlib/gtest/buildUnix
if [ ! -f "gtest.a" ]; then
echo "aaa"
fi


#build this prj
cd basepath/build/
cmake ../
make -j4
#make -j4 1>succ.txt 2>fail.txt

./DesignPattern

