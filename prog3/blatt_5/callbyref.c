#include <stdio.h>
#include <stdlib.h>

void free0(char** p){
    *p = NULL;
} // call by reference bedeutet, dass wir den speicher direkt addresieren und nicht den Wert als copy übergeben 



int main(void) {
char* p = malloc(10);
printf("%p\n", p); /* Ausgabe z. B. 0x470228 */
free0(&(p));
printf("%p\n", p); /* Ausgabe 0x0 oder 0 oder (nil) o. ä. */
return 0;
}