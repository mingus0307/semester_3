#include <stdio.h>



void print(void) { printf("Hallo\n"); }

void times(int  n, void (*fn)(void)){
    for (int i = 0; i < n; i++){
        fn(); 
    }
} 

int main(void){
    

    times(3, print); 
    
    return 0; 
}