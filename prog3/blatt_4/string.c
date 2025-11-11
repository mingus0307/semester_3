#include <stdio.h>
#include <string.h>
/*
* The strlen() function calculates the length of the string pointed to by s,
* excluding the terminating null byte ('\0').
*/
size_t mystrlen(const char *s) {
    unsigned int fin = 0; 
    
    for (const char* n = s; *n != '\0'; n++){
        fin++; 
    }

    return fin; 
}
/*
* The strcpy() function copies the string pointed to by src, including the
* terminating null byte ('\0'), to the buffer pointed to by dest.
* The strings may not overlap, and the destination string dest must be
* large enough to receive the copy.
* The strcpy() function returns a pointer to the destination string dest.
*/
char *mystrcpy(char *dest, const char *src) {
    while(*src != '\0'){
        *dest = *src; 
        src++; 
        dest++; 
    }
    *dest = '\0'; 
    return dest; 
}
/*
* The strcat() function appends the src string to the dest string,
* overwriting the terminating null byte ('\0') at the end of dest, and then
* adds a terminating null byte. The strings may not overlap, and the dest
* string must have enough space for the result.
* The strcat() function returns a pointer to the resulting string dest.
*/
char *mystrcat(char *dest, const char *src) {
    char * start = dest; 
    while (*dest != '\0'){
        dest++; 
    }

    while(*src != '\0'){
        *dest = *src; 
        src++; 
        dest++; 
    }
    *dest = '\0'; 
    return start; 
}
/*
* The strrchr() function returns a pointer to the last occurrence of the
* character c in the string s. Here "character" means "byte".
* The strrchr() function returns a pointer to the matched character or NULL if
* the character is not found. The terminating null byte is considered part of
* the string, so that if c is specified as '\0', these functions return a
* pointer to the terminator.
*/
char *mystrrchr(char *s, int c) {
    char* fin = NULL;
    
    for (char* n = s; *n != '\0'; n++){
        if (*n == c){
            fin = n; 
        }
    }
    return fin; 
}
/*
* The strstr() function finds the first occurrence of the substring needle in
* the string haystack. The terminating null bytes ('\0') are not compared.
* These functions return a pointer to the beginning of the located substring,
* or NULL if the substring is not found.
*/
char *mystrstr(char *haystack, char *needle) {
    char* found = NULL; 
    int isFound = 1; 
    
    for (char* hay = haystack; *hay != '\0'; hay++){
        if (*hay == *needle){
            isFound = 0; 
            // schauen wir ob das ganze Wort darin vorkommt
            int i = 1; 
            for (char* need = needle+1; *need != '\0'; need++){
                if(isFound == 1){
                    break; 
                }
                if(*need != *(hay + i) && *need != '\0' && *(hay +i) != '\0'){
                    isFound = 1; 
                }
                i++; 
            }
            if(isFound == 0){
                found = hay; 
            }
        }
    }
    
    
    //printf("%s \n", found);
    
    return found; 


}
int main(void) {
    char s1[] = "Dies ist ein Teststring!";
    char s2[] = "Und dies noch einer.";
    char buffer1[2000];
    char buffer2[2000];
    printf("mystrlen: %s\n",
    mystrlen(s1) == strlen(s1) ? "Richtig" : "Falsch");
    mystrcpy(buffer1, s1);
    printf("mystrcpy: %s\n", strcmp(buffer1, s1) == 0 ? "Richtig" : "Falsch");
    mystrcpy(buffer1, s1);
    mystrcat(buffer1, s2);
    strcpy(buffer2, s1);
    strcat(buffer2, s2);
    printf("mystrcat: %s\n", strcmp(buffer1, buffer2) == 0 ? "Richtig" : "Falsch");
    printf("mystrrchr: %s\n",
    mystrrchr(s1, 'i') == strrchr(s1, 'i') ? "Richtig" : "Falsch");
    printf("mystrstr: %s\n",
    mystrstr(s1, "Test") == strstr(s1, "Test") ? "Richtig" : "Falsch");
    return 0;
}