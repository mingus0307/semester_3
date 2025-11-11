#include <stdio.h>
#include <string.h>

void find(char* strings[], char** max){
    *max = strings[0]; 
    int i = 0; 

    while(strings[i] != NULL){
        if(strcmp(strings[i], *max) > 0){
            *max = strings[i]; 
        }
        i++; 
    }
}

char* find_c(char n[] , char c){
    char* fin; 
    char* foo = NULL;

    for (fin = n; *fin != '\0'; fin++){
        if (c == *fin){
            foo = fin; 
        }
    }

    return foo; 
}

int main(void){
    char * strings[] = {"abc","rst", "def", "rrr", NULL}; 
    char* max; 
    find(strings, &max);
    printf("%s\n", max); 
}