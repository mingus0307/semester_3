#include <stdio.h>


int get_input(char prompt[]){
    int input = 0; 

    printf("%s \n", prompt);
    scanf("%d", &input);

    return input; 
}