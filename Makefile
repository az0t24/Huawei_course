all: square_equation

square_equation: test.o functions.o square_equation.o
	gcc square_equation.o test.o functions.o -o square_equation -lm

square_equation.o: square_equation.c
	gcc -c square_equation.c -o square_equation.o

test.o: test.c
	gcc -c test.c -o test.o

functions.o: functions.c
	gcc -c functions.c -o functions.o
