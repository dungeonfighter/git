all: hello
	./main.o iris.txt 3
hello: kmeans.o
	g++ kmeans.o -o main.o
kmeans.o: kmeans.cpp
	g++ -g -c -std=c++11 -Wall kmeans.cpp
clean:
	rm -rf *.o  