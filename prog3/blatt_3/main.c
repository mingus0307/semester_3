#include <stdio.h>
#include <string.h>

struct int20 {
    char arr[20]; 
};

struct int20 create20(char a[]){
    struct int20 fin;
    size_t len_a = strlen(a);

    // wir füllen das moit 0en auf
    for (int i = 0; i < 20; i++){
        fin.arr[i] = '0';  
    }

    // wir kopieren die Zahl ans Ende des Arrays
    for (int i = 0; i < len_a; i++){
        fin.arr[20 - len_a + i] = a[i];
    }

    return fin;  
}






int char_as_int(char c){
    // nice to know: das klappt nicht grundsätzlich as char to int, man könnte es einfach
    return c - '0'; 
}

int int_as_char(int c){
    // nice to know: das klappt nicht grundsätzlich as char to int, man könnte es einfach
    return c + '0'; 
}

struct int20 add20(struct int20 a, struct int20 b){
    struct int20 fin; 
    size_t len_a = sizeof(a.arr) / sizeof(a.arr[0]);
    size_t len_b = sizeof(b.arr) / sizeof(a.arr[0]); 

}

void print20(struct int20 n) {
    int leading_zero = 1;

    for (int i = 0; i < 20; i++) {
        if (n.arr[i] != '0') {
            leading_zero = 0;
        }
        // wenn keine 0en mehr kommen, fang an die chars auszugeben
        if (!leading_zero) {
            putchar(n.arr[i]);
        }
    }
}

 
int main(void){
    struct int20 a= create20("12345678901234567890");
    struct int20 b= create20("100");
    struct int20 sum= add20(a, b);
    print20(a); printf("\n");
    print20(b); printf("\n");
    print20(sum); printf("\n");
}