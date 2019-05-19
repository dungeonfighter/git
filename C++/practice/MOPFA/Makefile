
CC = g++
exe = exec
obj = main.o PFA.o function.o

all:$(obj)
	$(CC) -std=c++11 $(obj) -o $(exe)   
%.o:%.cpp
	$(CC) -g -c -std=c++11 -Wall $^ 

.PHONY:clean
clean:
	rm -rf $(obj) $(exe)


