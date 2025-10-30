#include <stdio.h>
#include <stdlib.h>
    
#define NAME_LEN 40
#define ARRAY_LEN 10

typedef struct {
char name[NAME_LEN+1];
int personalnummer;
float gehalt;
} angestellter;



int main(void){
    //Speicherbereich der 10 Angestellen Pointer enthält 
    angestellter* arr[ARRAY_LEN];   

    // Nullen der Pointer im Array
    for (angestellter** pt = arr; pt < arr+ARRAY_LEN; pt++){
        *pt = NULL; 
    }

    int eingabe =  -1 ;

    while(eingabe == -1 ){
        printf("bitte Nummer angeben (index zwischen 0-9): \n");  
        scanf("%d", &eingabe);
        if(eingabe >= 9 || eingabe < 0){
            eingabe = -1; 
        } 
    }
    // wenn array an der stelle leer -> neuen angestellten erstellen 
    if(arr[eingabe] == NULL){
        arr[eingabe] = (angestellter*) malloc(sizeof(angestellter)); 

        printf("Neuer Angestellter?\n Name eingeben: \n"); 
        scanf("%40s", arr[eingabe]->name);

        printf("Personalnummer eingeben: \n"); 
        scanf("%d", &arr[eingabe]->personalnummer);

        printf("Gehalt eingeben: \n"); 
        scanf("%f", &arr[eingabe]->gehalt);

    }else{ // sonst löschen wir das ganze raus und machen den Speicher, den es belegt. vorsichtshalber nullen, weil wer weiß       
        free(arr[eingabe]); 
        arr[eingabe] = NULL; 
    }

    printf("Alle Angestellten: \n"); 
    for (int i = 0; i < ARRAY_LEN; i++){
        printf("Name: \n %s", arr[i]->name);
        printf("Personalnummer: \n %d", arr[i]->personalnummer);
        printf("Gehalt: \n %f", arr[i]->gehalt); 
        printf("\n"); 
    }




}