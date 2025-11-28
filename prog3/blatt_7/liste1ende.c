#include <stdio.h>
#include <stdlib.h>

struct knoten {
    int wert; /* oder komplexere Daten */
    struct knoten* next;
};

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
struct knoten* entfernen_kopf(struct knoten* *kopfref, struct knoten* *enderef);

/* Liefert den entfernten Knoten oder NULL */
struct knoten* entfernen_ende(struct knoten* *kopfref, struct knoten* *enderef);

/* Liefert den entfernten Knoten oder NULL */
struct knoten* entfernen(struct knoten* *kopfref, struct knoten* *enderef, struct knoten* auszufueg);