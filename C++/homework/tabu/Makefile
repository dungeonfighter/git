all: exec 
	./main.o eil51.tsp
exec: Tabu.o
	g++ -g Tabu.o -o main.o
Tabu.o: Tabu.cpp
	g++ -g -c -Wall Tabu.cpp

clean:
	rm -rf *.o  


