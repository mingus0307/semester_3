#include <stdio.h>

void copy_arr(int* a, int* b){
    
    for (int* pt = a+4; pt >= a; pt--){
        *b = *pt; 
        b++; 
    } 

}

int main(void){
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];
    copy_arr(a, b); 

    for (int * pt = b; pt < b+5; pt++){
        printf("%d \n", *pt);
    } 

}