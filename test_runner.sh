#!/bin/bash

make clean
make
./PiezasTest
gcov -rbc Piezas.cpp
cat Piezas.cpp.gcov