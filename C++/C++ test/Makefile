
CC = g++
cxxflag = -std=c++11 -Wall
exe = main
obj = test.o 
thread = -pthread 
# src = 

all:$(obj)
	$(CC) $(cxxflag) -pthread $(obj) -o $(exe)   
	
%.o:%.cpp
	$(CC) -g -c -pthread $(cxxflag) $^ 

.PHONY:clean
clean:
	rm -rf $(obj) $(exe)


#多行註解範例
ifeq ("x","y")
CC = g++
EXE = exe
objects = read_file_double
all:exe
	./exe
exe:$(objects).o
	$(CC)  -pthread $(objects).o -o exe
$(objects).o:$(objects).cpp
	g++ -g -c -pthread -std=c++11 -Wall $(objects).cpp

clean:
	rm -rf *.o  
endif
