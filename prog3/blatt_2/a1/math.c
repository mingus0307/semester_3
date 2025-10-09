#include <stdio.h>
#include "summe.h"
#include "differenz.h"


char input;  // input des users 



void berechne(){
    int result = 0; 
    printf("Ihre Wahl?: \n <S>umme oder <D>ifferenz\n");
    scanf("%c", &input);    
    if(input == 'S'){
        result = summe(); 
    }else if(input == 'D'){
        result = differenz(); 
    }

    printf("Ihr Ergebnis: %d \n", result); 
}


