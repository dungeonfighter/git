GG = gcc
CC = g++
cxxflag = -std=c++11 -Wall
exe = arp
obj = arp.o main.o 


all:$(obj)
	$(GG) -Wall $(obj) -o $(exe)   
%.o:%.c
	$(GG) -c -Wall $^ 

.PHONY:clean
clean:
	rm -rf $(obj) $(exe)



