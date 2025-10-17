#include <stdio.h> 
int main(void) { 
    int i; 
    int* ip; 
    printf("Eingabe: "); 
    scanf("%d", &i); 
    ip = &i; // & verwandet alles in die Adresse wo es im Speicher steht 
    printf("Eingabe war %d\n", 
           *ip ); // * macht so ziemlich das Gegenteil von & also sagt uns was an einer Adresse drin steht im Speicher 
    return 0; 
}