#include <stdio.h>


void tausche_int(int* a, int* b){
    int c = 0; 


    c = *a;
    *a = *b; 
    *b = c; 
    // muss über pointer laufen wegen Call by value
    // über pointer ist dann durch call by reference sicher

}

void tausche_intPtr(int** pa, int** pb){
    int* c; 


    c = *pa;
    *pa = *pb; 
    *pb = c; 
}


int main(void) {

int i = 1; int j = 2;
printf("i = %d, j = %d\n", i, j); /* Gibt 1 und 2 aus */
tausche_int(&i, &j);
printf("i = %d, j = %d\n", i, j); /* Gibt 2 und 1 aus */

// test für pointer-tausch 

int* a; int* b;

int temp = 6; 
int foo = 9; 

a = &temp; 
b = &foo; 

int** pa = &a; 
int** pb = &b; 


printf("a = %d, b = %d\n", *a, *b);
tausche_intPtr(pa, pb);
printf("a = %d, b = %d\n", *a, *b);
return 0;
}