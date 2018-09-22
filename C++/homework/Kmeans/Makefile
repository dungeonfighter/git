all: hello
	./main.o iris.txt 3
hello: kmeans.o
	g++ kmeans.o -o main.o
kmeans.o: kmeans.cpp
	g++ -g -c -Wall kmeans.cpp
clean:
	rm -rf *.o  