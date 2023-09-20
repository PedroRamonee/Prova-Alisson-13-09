all: compile link run

delete:
	del *.o

compile:
	g++ -c main.cpp 

link:
	g++ *.o -o main 

run:
	./main.exe
