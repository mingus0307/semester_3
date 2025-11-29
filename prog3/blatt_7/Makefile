GCC_ARGS = -std=c99 -pedantic-errors -Wall -Wstrict-prototypes
OBJ = liste1ende.o liste1endetest.o 

main : $(OBJ)
	gcc $(GCC_ARGS) -o main $(OBJ)

%.o : %.c liste1ende.h
	gcc $(GCC_ARGS) -c $<


