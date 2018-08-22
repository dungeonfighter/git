all: exec 
	./main.o eil51.tsp
exec: PSO.o Main.o 
	g++ -g PSO.o Main.o -o main.o
PSO.o: PSO.cpp
	g++ -g -c -Wall PSO.cpp
Main.o:
	g++ -g -c -Wall Main.cpp

clean:
	rm -rf *.o  

test: exect
	./testmain.o 123
exect: test.o
	g++ -g -std=c++11 test.o -o testmain.o
test.o: test.cpp
	g++ -g -c -std=c++11 -Wall test.cpp
