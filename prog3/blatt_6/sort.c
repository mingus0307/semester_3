#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct { 
  char name[15]; /* Platz für Schmidt_1234 */ 
  int gehalt; 
} angestellter;


int compare(const void* a,const void* b){
    return (*(int*)a - *(int*)b); 
}

// random array mit 100 zahlen zwischen 1-1000
int* randArr(){
    int* arr = malloc (100 * sizeof(int));

    for (int i = 0; i < 100; i++){
        arr[i] = rand() % (1000) + 1; 
    }

    qsort(arr, 100, sizeof(int), compare);

    return arr; 
}

int compare_angst(const void* a, const void* b){
    const angestellter*  x = a; 
    const angestellter* y = b; 

    return (x->gehalt - y->gehalt);
}

angestellter* randAngstArr(){
    angestellter* arr = malloc(100 * sizeof(angestellter)); 

    for (int i = 0; i < 100; i++){
        char nAsString[] = "0000"; 
        strcpy(arr[i].name, "Schmidt_"); 
        sprintf(nAsString, "%d", rand() % (1000) + 1); 
        strcat(arr[i].name, nAsString);

        arr[i].gehalt = rand() % (6000 - 2000 +1) + 2000; 
        
    }
    qsort(arr, 100, sizeof(angestellter), compare_angst); 
    return arr; 
}



int main(void){
    srand(time(NULL));

    int* arr = randArr(); 

    for (int* ptr = arr; ptr < arr +100; ptr++){
        printf(" %d\n", *ptr);
    }

    angestellter* ang = randAngstArr(); 

    for (int i = 0; i < 100; i++) {
        printf("name: %s\ngehalt: %d\n", ang[i].name, ang[i].gehalt);
    }




    return 0; 
}