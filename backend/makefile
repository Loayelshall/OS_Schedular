
run: compile
	./main

run_clean: clean compile
	./main

compile: SJF.o FCFS.o PRI.o main.o
	g++ main.o FCFS.o SJF.o PRI.o -g -o main	

PRI.o:
	g++ -c PRI.cpp

FCFS.o:
	g++ -c FCFS.cpp

SJF.o:
	g++ -c SJF.cpp

main.o:
	g++ -c main.cpp

clean: 
	rm *.o main	