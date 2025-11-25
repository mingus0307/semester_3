#include <stdio.h>



void print(void) { printf("Hallo\n"); }

void times(int  n, void (*fn)(void)){
    for (int i = 0; i < n; i++){
        fn(); 
    }
} 

int main(void){
    int foo = 3; 
    void (*fn)(void) = print; 

    times(foo, print); 
    
    return 0; 
}