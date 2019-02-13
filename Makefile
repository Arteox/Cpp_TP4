CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
OBJ = Noeud.o ListeNoeud.o Date.o main.o ListeCible.o GraphViz.o ExtractionLog.o
DEPS = Noeud.h ListeNoeud.h Date.h ListeCible.h GraphViz.h ExtractionLog.h

analog: $(OBJ)
	$(CC) -g $^ -o $@
	./analog tmp/tresCourt.log
	#valgrind --leak-check=full ./analog /tmp/court.log
	
analogG: $(OBJ)
	$(CC) -g $^ -o $@
	./analogG -g /tmp/court3.dot tmp/court3.log

%.o: %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
	
.PHONY: clean

clean : 
	rm -rf *.ex *.o core analog analogG *.png *.dot