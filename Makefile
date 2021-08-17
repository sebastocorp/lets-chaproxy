# TODO: create a makefile for lets haproxy
CC=g++
CFLAGS=-Wall -pedantic -std=c++2a -O3
ARGS=

make:
	$(CC) -o build/bin/lets $(CFLAGS) src/main.cpp

run:
	./build/bin/lets $(ARGS)