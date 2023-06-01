mycomp: mycomp.o input_utils.o complex.o
	gcc -g -ansi mycomp.o input_utils.o complex.o -o mycomp -lm

mycomp.o: mycomp.c input_utils.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o

input_utils.o: input_utils.c complex.o input_utils.h
	gcc -c -Wall -ansi -pedantic input_utils.c -o input_utils.o

complex.o: complex.c complex.h
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o -lm
