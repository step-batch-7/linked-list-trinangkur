#! /bin/zsh

rm -rf bin

rm -rf *.o
gcc -c ./test/test.c list.c
mkdir bin
gcc -o ./bin/test *.o
rm -rf *.o

./bin/test