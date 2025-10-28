#include <stdio.h>


void tausche_int(int* a, int* b){
    int c = 0; 


    c = *a;
    *a = *b; 
    *b = c; 
    // muss über pointer laufen wegen Call by value
    // über pointer ist dann durch call by reference sicher

}


int main(void) {

int i = 1; int j = 2;
printf("i = %d, j = %d\n", i, j); /* Gibt 1 und 2 aus */
tausche_int(&i, &j);
printf("i = %d, j = %d\n", i, j); /* Gibt 2 und 1 aus */
return 0;
}