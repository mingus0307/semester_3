#include <stdio.h>
#include <stdlib.h>

struct knoten {
    int wert; /* oder komplexere Daten */
    struct knoten* next;
};


void durchlaufen(struct knoten* kopf) {
    struct knoten* laufzeiger;
    laufzeiger = kopf;
    while (laufzeiger!=NULL) {
        printf("%d ",laufzeiger->wert);
        laufzeiger = laufzeiger->next;
    }
    printf("\n");
}



struct knoten* suchen(struct knoten* kopf, int gesuchter_wert) {
    struct knoten* laufzeiger;
    laufzeiger = kopf;
    while ((laufzeiger!=NULL)&&(laufzeiger->wert!=gesuchter_wert)) {
        laufzeiger = laufzeiger->next;
    }
    return laufzeiger;
}

/* Liefert -1 im Fehlerfall, sonst 0 */
int einfuegen_kopf(struct knoten* *kopfref, struct knoten* *enderef, struct knoten* einzufueg){
    if ((einzufueg==NULL)||(kopfref==NULL)||(enderef==NULL)) return -1;

    if(*kopfref == NULL && *enderef == NULL){
        einzufueg->next = NULL; 
        *kopfref = einzufueg; 
        *enderef = einzufueg; 
        return 0; 
    }

    einzufueg->next = *kopfref;
    *kopfref = einzufueg;
    return 0;
}

/* Liefert -1 im Fehlerfall, sonst 0 */
int einfuegen_nach(struct knoten* nachdiesem, struct knoten* einzufueg, struct knoten* *enderef){
    if ((nachdiesem==NULL)||(einzufueg==NULL)||(enderef==NULL))  return -1;

    if (*enderef == nachdiesem){
        *enderef = einzufueg; 
    }
    
    einzufueg->next = nachdiesem->next;
    nachdiesem->next = einzufueg;
    return 0;
}

/* Liefert -1 im Fehlerfall, sonst 0 */
int einfuegen_ende(struct knoten* *kopfref, struct knoten* *enderef, struct knoten* einzufueg){
    if ((einzufueg==NULL)||(kopfref==NULL)||(enderef==NULL)) return -1;
    if(*kopfref == NULL && *enderef == NULL){
        einfuegen_kopf(kopfref, enderef, einzufueg); 
        return 0; 
    }
    einfuegen_nach(*enderef, einzufueg, enderef);
    return 0;  
}

/* Liefert den entfernten Knoten oder NULL */
struct knoten* entfernen_kopf(struct knoten* *kopfref, struct knoten* *enderef){
    if ((kopfref==NULL)||(*kopfref==NULL)||(enderef==NULL)) return NULL;

    struct knoten* alt = *kopfref; 
    *kopfref = alt->next; 

    if (*kopfref == NULL){
        *enderef = *kopfref; 
    }
    

    return alt; 
}

/* Liefert den entfernten Knoten oder NULL */
struct knoten* entfernen_ende(struct knoten* *kopfref, struct knoten* *enderef){
    if ((kopfref==NULL)||(enderef==NULL)||(*kopfref==NULL)) return NULL;

    struct knoten* alt = *enderef; 
    struct knoten* vorletzter = *kopfref; 

    if(*kopfref == *enderef){
        *kopfref = NULL; 
        *enderef = NULL; 
        return alt; 

    }

    while(vorletzter->next != *enderef){
        vorletzter = vorletzter->next; 
    }

    *enderef = vorletzter; 
    vorletzter->next = NULL; 

    return alt; 

}

/* Liefert den entfernten Knoten oder NULL */
struct knoten* entfernen(struct knoten* *kopfref, struct knoten* *enderef, struct knoten* auszufueg){
    if ((auszufueg==NULL)||(kopfref==NULL)||(*kopfref==NULL)) return NULL;

    // 1. FALL liste hat ein element 

    if (*enderef == *kopfref && auszufueg == *kopfref){
        // weil dann gibt es ja nur ein Glied was entfernt werden kann 
        *kopfref = NULL; 
        *enderef = NULL;  
        return auszufueg; 
    }

    if(*kopfref == auszufueg){
        entfernen_kopf(kopfref, enderef); 
        return auszufueg; 
    }else if (*enderef == auszufueg) {
        entfernen_ende(kopfref, enderef); 
        return auszufueg; 
    }

    // 3.FALL liste hat mehrere glieder 
    struct knoten* vor_auszufueg = *kopfref; 

    while(vor_auszufueg->next != auszufueg){
        if(vor_auszufueg->next == NULL){
            return NULL; 
        }
        vor_auszufueg = vor_auszufueg->next; 
    }

    vor_auszufueg->next = auszufueg->next; 
    return auszufueg; 

}