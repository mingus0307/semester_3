#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char* argv[]){
    if (argc < 3){
        printf("Benutzung: ./plus <zahl> <zahl>\n"); 
        return 1; 
    }
    char* endptr = NULL; 
    char* end_two = NULL; 
    errno = 0;

    for (int i = 1; i < argc;  i++){
        for (char * ptr = argv[i]; *ptr != '\0'; ptr++){
            if (*ptr < 48 || *ptr > 57){
                printf("Kann '%s' nicht in Zahl umwandeln: Falsches Format\n", argv[i]); 
                return 0; 
            }
        }
    }
    
    long first = strtol(argv[1], &endptr ,10);
    if (errno != 0){
        printf("Kann '%s' nicht in Zahl umwandeln: %s\n", argv[1], strerror(errno));
    }
    long sec = strtol(argv[2], &end_two, 10); 
    if (errno != 0){
        printf("Kann '%s' nicht in Zahl umwandeln: %s\n", argv[2], strerror(errno));
    }

    

    long fin = first + sec; 

    printf("%ld + %ld = %ld\n", first, sec, fin); 
 
    return 0; 
}