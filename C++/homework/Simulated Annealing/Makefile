all: hello
	./main.o data.txt ans.txt
hello: SA.o
	g++ -std=c++11 SA.o -o main.o
SA.o: SA.cpp
	g++ -std=c++11 -c -Wall SA.cpp
clean:
	rm -rf *.o  
