
#include <stdio.h>
#include <string.h>

int main(void) {
    char eingabe[32] = "";
    char passwort[32] = "GeHeIm";  /* Dem Programmbenutzer unbekannt */
    

    /* Ggf. muessen Sie die Reihenfolge der beiden vorstehenden 
       Array-Definitionen umkehren, um den unten beschriebenen Effekt
       zu beobachten (plattformabhaengig). Auf den Pool-PCs ist die obige
       Reihenfolge die richtig, um den gewuenschten Effekt zu beobachten.
    */

    printf("eingabe[] = %s\n", eingabe);
    printf("passwort[] = %s\n", passwort);

    printf("Bitte Passwort fuer den Hochsicherheitsbereich eingeben:\n");

    /* read all including spaces and tabs to the end of the line */
    scanf("%32s[^\n]", eingabe);

    if (!strncmp(eingabe, passwort, strlen(passwort))) {
      printf("Passwort korrekt - Willkommen im Hochsicherheitsbereich!\n");
      return 0;
    } else {
      printf("Passwort falsch - Zugang verweigert!\n");
      return -1;
    }
} // Bla                             Bla
// Der Stack läuft quasi über, denn wir sprengen den vorgegebenen Rahmen der für unseren Input vorgesehen ist. 
// Dadurch überschreiben wir das tatsächliche Passwort und vergleichen es mit unserem eigenen Input 
// -> radikale Sicherheitslücke 


// Fixen tun wir das über einen Width parameter in scanf() der exakt bestimmt wie viel eingelesen werden kann