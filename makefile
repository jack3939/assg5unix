SHELL = /bin/sh
FLAGS = -g -Wall
CC = g++

all: twopipestwochildren twopipesthreechildren DynPipe

p1: twopipestwochildren.cpp
	$(CC) $(FLAGS) -o $@ twopipestwochildren.cpp
p2: twopipesthreechildren.cpp
	$(CC) $(FLAGS) -o $@ twopipesthreechildren.cpp
p3: DynPipe.cpp
	$(CC) $(FLAGS) -o #@ DynPipe.cpp

clean:
	rm twopipestwochildren rm twopipesthreechildren rm DynPipe
