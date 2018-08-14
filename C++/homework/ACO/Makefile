all: exec 
	./main.o eil51.tsp
exec: Aco.o Main.o 
	g++ -g Aco.o Main.o -o main.o
Aco.o: Aco.cpp
	g++ -g -c -Wall Aco.cpp
Main.o:
	g++ -g -c -Wall Main.cpp
clean:
	rm -rf *.o  


