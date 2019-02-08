CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
OBJ = Noeud.o ListeNoeud.o Date.o main.o
DEPS = Noeud.h ListeNoeud.h Date.h

Main.ex: $(OBJ)


%.ex: 
	$(CC) -g $^ -o $@
	./$@
	#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --max-stackframe=10485760 ./$@

%.o: %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
	
.PHONY: clean

clean : 
	rm -rf *.ex *.o core