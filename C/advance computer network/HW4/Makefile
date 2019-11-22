GG = gcc
CC = g++
cxxflag = -std=c++11 -Wall
exe = Ping
obj = main.o icmp.o


all:$(obj)
	$(GG) -Wall $(obj) -o $(exe)   
%.o:%.c
	$(GG) -c -Wall $^ 

.PHONY:clean
clean:
	rm -rf $(obj) $(exe)



