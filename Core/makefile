
run: compile
	./main

run_clean: clean compile
	./main

compile: SJF.o FCFS.o PRI.o RR.o avg_time.o main.o
	g++ main.o FCFS.o SJF.o RR.o PRI.o avg_time.o -g -o main	

PRI.o:
	g++ -c PRI.cpp

FCFS.o:
	g++ -c FCFS.cpp

SJF.o:
	g++ -c SJF.cpp

RR.o:
	g++ -c RR.cpp

avg_time.o:
	g++ -c avg_time.cpp

main.o:
	g++ -c main.cpp

clean: 
	rm *.o main	