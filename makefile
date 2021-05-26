CC = g++
flags = 
exe = blakcjack.exe

output: main.o player.o deck.o
	$(CC) $(flags) -o $(exe) main.o player.o deck.o

player.o: player.cpp player.h
	$(CC) $(flags) -o player.o player.cpp -c

deck.o: deck.cpp deck.h
	$(CC) $(flags) -o deck.o deck.cpp -c

main.o: main.cpp player.h
	$(CC) $(flags) -o main.o main.cpp -c

run:
	make
	./output.exe

clear:
	rm *.o $(exe)