CC = g++

output: main.o
	g++ main.o -o output.o

main: main.cpp
	g++ -c main.cpp -o main.o

run:
	make
	./output.o

clear:
	rm *.o output.txt