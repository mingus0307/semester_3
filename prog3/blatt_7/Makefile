GCC_ARGS = -std=c99 -pedantic-errors -Wall -Wstrict-prototypes
OBJ = liste1ende.o liste1endetest.o 

main : $(OBJ)
	gcc $(GCC_ARGS) -o main $(OBJ)

liste1ende.o : liste1ende.c liste1ende.h 
	gcc $(GCC_ARGS) -c liste1ende.c

liste1endetest.o : liste1endetest.c liste1ende.h 
	gcc $(GCC_ARGS) -c liste1endetest.c


