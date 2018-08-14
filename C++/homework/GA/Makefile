all: exec 
	./main.o eil51.tsp
exec: GA.o Main.o 
	g++ -g GA.o Main.o -o main.o
GA.o: GA.cpp
	g++ -g -c -Wall GA.cpp
Main.o:
	g++ -g -c -Wall Main.cpp

clean:
	rm -rf *.o  


