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
    // nice to know: das klappt nicht grundsätzlich als char to int
    return c - '0'; 
}

int int_as_char(int c){
    // das natürlich auch nicht grundsätzlich als int to char
    return c + '0'; 
}

struct int20 add20(struct int20 a, struct int20 b){
    struct int20 fin; 
     int übertrag = 0;

    for (int i = 19; i >= 0; i--){
       
        // wir nehmen die letzten zwei chars der Zahlen
        int a_last = char_as_int(a.arr[i]);
        int b_last = char_as_int(b.arr[i]);

        // wenn übertrag besteht, addieren wir ihn auf a 
        if (übertrag > 0){
            a_last += übertrag;
            übertrag = 0; // wir setzen den Übertrag zurück
        }

        // addieren der einzelnen aktuellen Ziffern
        int sum = a_last + b_last;

        // übertrag check 
        if (sum >= 10){
            übertrag = 1;
            sum  = sum % 10; // wir nehmen den Übertrag
        }
        // schreiben wir in den letzten char des Ergebnisses
        fin.arr[i] = int_as_char(sum);
    }

    return fin;

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
    // printf("letzter Eintrag: %c\n", a.arr[19]);
}