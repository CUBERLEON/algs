#! /bin/bash
for filename in ./codes/*.cpp; do
    g++ -std=c++11 $filename -o $filename.run
    rm -f $filename.run
done
