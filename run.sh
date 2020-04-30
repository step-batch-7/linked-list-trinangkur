#! /bin/zsh

rm -rf bin

rm -rf *.o
gcc -c *.c
mkdir bin
gcc -o ./bin/main *.o
rm -rf *.o

./bin/main