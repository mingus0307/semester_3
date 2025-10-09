GCC_ARGS = -std=c99 -pedantic-errors -Wall -Wstrict-prototypes
OBJ = main.o math.o summe.o differenz.o input.o

main : $(OBJ)
	gcc $(GCC_ARGS) -o main  $(OBJ)

main.o : main.c math.h
	gcc $(GCC_ARGS) -c main.c 

math.o : math.c summe.h differenz.h 
	gcc $(GCC_ARGS) -c math.c

summe.o : summe.c input.h 
	gcc $(GCC_ARGS) -c summe.c 

differenz.o : differenz.c input.h 
	gcc $(GCC_ARGS) -c differenz.c 

input.o : input.c 
	gcc $(GCC_ARGS) -c input.c 
