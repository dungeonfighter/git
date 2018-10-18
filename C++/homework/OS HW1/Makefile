all: exec 
	./Main.exe 
exec: ninefouros.o main.o
	g++ -g ninefouros.o main.o -o Main.exe
ninefouros.o: ninefouros.cpp
	g++ -g -c -Wall ninefouros.cpp
main.o:
	g++ -g -c -Wall main.cpp

clean:
	del *.o *.exe  

