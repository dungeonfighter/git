CC = g++
EXE = exe
objects = read_file_double
all:exe
	./exe
exe:$(objects).o
	$(CC)  $(objects).o -o exe
$(objects).o:$(objects).cpp
	g++ -g -c -std=c++11 -Wall $(objects).cpp

clean:
	rm -rf *.o  