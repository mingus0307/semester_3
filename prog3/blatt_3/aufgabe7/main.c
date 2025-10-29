#include <stdio.h> 
int main(void) { 
    int i; 
    int* ip; 
    printf("Eingabe: "); 
    ip = &i; // & verwandet alles in die Adresse wo es im Speicher steht 
    scanf("%d", 0x12345678); // ip); // &i); 
    printf("Eingabe war %d\n", 
           *ip ); // * macht so ziemlich das Gegenteil von & also sagt uns was an einer Adresse drin steht im Speicher 
    return 0; 
}