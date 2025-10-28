#include <time.h>
#include <stdio.h>


int main(void){
    time_t a[2] = {49888800, 645703200}; 

    //char* lol = ctime(a);


    for (time_t* temp = a; temp < a + 2; temp++){
        printf("zeit in richtig: %s", ctime(temp)); 
    }
}