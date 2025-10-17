#include <stdio.h>
#include <string.h>

struct int20 {
    char arr[20]; 
};

struct int20 create20(char a[]){
    struct int20 fin;

    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++){
        fin.arr[i] = a[i];  
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

    // an letzte stelle gehen und addieren 

    for (int i = 1; i < len_b ; i++){
        int a_as_int = char_as_int(a.arr[len_a-i]); 
        int b_as_int = char_as_int(b.arr[len_b-i]);

        if(( a_as_int + b_as_int ) / 10 > 1){
            fin.arr[len_a -i -1] = int_as_char(char_as_int(fin.arr[len_a -i -1]) + 1);  
        } else {
            fin.arr[len_a-i] = int_as_char(a_as_int + b_as_int);
        }
    } 

    // schauen ob es einen üerhang gibt 
    // wenn überhang, dann einen an der nächsten stelle beim längeren arr auf rechnen 
        
    return fin; 
}



void print20(struct int20 a){
    for (int i = 0; i < ){
        printf("%c", a.arr[i]);
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