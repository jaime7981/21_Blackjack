CC = g++
flags = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe = blakcjack.exe

output: main.o player.o deck.o table.o card.o
	$(CC) $(flags) -o $(exe) main.o player.o deck.o table.o card.o

card.o: card.cpp card.h
	$(CC) $(flags) -o card.o card.cpp -c

table.o: table.cpp table.h
	$(CC) $(flags) -o table.o table.cpp -c

player.o: player.cpp player.h
	$(CC) $(flags) -o player.o player.cpp -c

deck.o: deck.cpp deck.h
	$(CC) $(flags) -o deck.o deck.cpp -c

main.o: main.cpp
	$(CC) $(flags) -o main.o main.cpp -c

run:
	make
	./$(exe)

clear:
	rm *.o $(exe)