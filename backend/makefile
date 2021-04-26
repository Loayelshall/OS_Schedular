
run: compile
	./main

run_clean: clean compile
	./main

compile: SJF.o FCFS.o main.o
	g++ main.o FCFS.o SJF.o -g -o main	

FCFS.o:
	g++ -c FCFS.cpp

SJF.o:
	g++ -c SJF.cpp

main.o:
	g++ -c main.cpp

clean: 
	rm *.o main	