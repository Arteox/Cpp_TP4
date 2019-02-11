CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
OBJ = Noeud.o ListeNoeud.o Date.o main.o ListeCible.o GraphViz.o
DEPS = Noeud.h ListeNoeud.h Date.h ListeCible.h GraphViz.h

analog: $(OBJ)
	$(CC) -g $^ -o $@
	./analog court.log
	#valgrind --leak-check=full ./analog court.log
	
analogG: $(OBJ)
	$(CC) -g $^ -o $@
	./analogG -g court2.dot court2.log

%.o: %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
	
.PHONY: clean

clean : 
	rm -rf *.ex *.o core analog analogG *.png *.dot