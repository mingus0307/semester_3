#include <stdio.h>

double mehrwertsteuer(double netto){
    return (netto / 100) * 19; 
}

double brutto(double netto){
    return netto + mehrwertsteuer(netto); 
}

double netto(double brutto){
    return brutto - mehrwertsteuer(brutto); 
}

int main (void){
    printf("Ihre Eingabe\n \t<funktion> [<betrag>]\nBedeutung von <funktion>: 0=Mwst. vom Netto, 1=Brutto vom Netto, 2=Netto vom Brutto, 3=Ende\nz. B. 0 99.95      (für die Berechnung der Mehrwertsteuer von 99.95 netto)\n"); 
    
    int func; 
    double val; 
    scanf("%d",&func);

    if (func == 3){
        return 0; 
    }
    scanf("%le", &val); 

    double (*functions[3])(double) = {
       mehrwertsteuer,
       brutto, 
       netto 
    }; 

    double fin = functions[func](val); 

    if (func == 0) printf("Mwst. vom Netto: %.2f\n", fin);
    if (func == 1) printf("Brutto vom Netto: %.2f\n", fin);
    if (func == 2) printf("Netto vom Brutto: %.2f\n", fin);
    
    
    return 0; 
}