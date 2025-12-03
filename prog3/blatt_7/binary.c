#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define NAME_LEN 10 

typedef struct  angestellter{
    char name[NAME_LEN+1];
    int personalnummer;
    float gehalt;
}Angestellter; 

void binaer_speichern(Angestellter arr[],int anz){
    FILE* fp = fopen("angestellte.dat" ,"wb"); 
    if (!fp) {
        perror("fopen");
        return; 
    }
    
    size_t written = fwrite(arr, sizeof(Angestellter), anz, fp); 
    fclose(fp);
}

void binaer_laden_und_ausgeben(void){
    FILE* fp = fopen("angestellte.dat", "rb"); 
    if (!fp){perror("fopen");}; 

    Angestellter* arr = malloc(sizeof(Angestellter) * 5); 
    size_t read = fread(arr, sizeof(Angestellter), 5, fp);

    for (int i = 0; i < 5; i++){
        
        printf("name: %s\ngehalt: %2.f\nperso: %d\n\n", arr[i].name, arr[i].gehalt, arr[i].personalnummer); 
    }

    fclose(fp); 

}

int main(void){

    srand(time(NULL));  
    Angestellter* arr = (Angestellter*)malloc(sizeof(Angestellter) * 5);

    int i = 1; 

    for (Angestellter* ptr = arr; ptr < arr + 5; ptr++){
        char n_as_string[] = "0000"; 
        strcpy(ptr->name, "Klaus_"); 
        sprintf(n_as_string, "%d", rand() % (1000) + 1); 
        strcat(ptr->name, n_as_string); 
        
        ptr->gehalt = rand() % (6000 - 2000 + 1) + 2000; 
        ptr->personalnummer = i; 
        i++; 
    }

    binaer_speichern(arr, 5);
    binaer_laden_und_ausgeben(); 




   /* for (int i = 0; i < 5; i++){
        printf("name: %s\ngehalt: %2.f\nperso: %d\n\n", arr[i].name, arr[i].gehalt, arr[i].personalnummer); 
    } */




    return 0; 
}