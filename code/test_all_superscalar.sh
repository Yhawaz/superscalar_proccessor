#!/bin/bash

echo "Testing add"
./test.sh add32
timeout 5 ./top_superscalar | grep -v Warning

echo "Testing and"
./test.sh and32
timeout 5 ./top_superscalar | grep -v Warning

echo "Testing or"
./test.sh or32
timeout 5 ./top_superscalar | grep -v Warning

echo "Testing sub"
./test.sh sub32
timeout 5 ./top_superscalar | grep -v Warning

echo "Testing xor" 
./test.sh xor32
timeout 5 ./top_superscalar | grep -v Warning

echo "Testing hello"
./test.sh hello32
timeout 5 ./top_superscalar | grep -v Warning

echo "Testing mul"
./test.sh mul32
timeout 5 ./top_superscalar | grep -v Warning

echo "Testing reverse"
./test.sh reverse32
timeout 15 ./top_superscalar | grep -v Warning

echo "Testing thelie"
./test.sh thelie32
timeout 20 ./top_superscalar | grep -v Warning

echo "Testing thuemorse"
./test.sh thuemorse32
timeout 20 ./top_superscalar | grep -v Warning

echo "Testing matmul"
./test.sh matmul32
timeout 90 ./top_superscalar | grep -v Warning

