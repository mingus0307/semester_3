void mystrcat(char dest[], char src[]) {
    // ende von dest finden
    int i = 0;  
    while (dest[i] != '\0'){
        i++; 
    }
    //ab dem index src anhängen 
    int j = 0; 
    while (src[j] != '\0'){
        dest[i] = src[j]; 
        j++; 
        i++; 
    }
    // den String noch abschließen
    dest[i] = '\0'; 
}