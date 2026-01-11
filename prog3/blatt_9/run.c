#include <stdio.h>
#include <stdlib.h>

int incr(int i) { return i+1; }

int iterate(int n, int foo, int (*fp)(int j)){
 
    for (int i = 0; i < n; i++){
        foo = fp(foo); 
    }

    return foo; 
}
struct Node {
    int  val; 
    struct Node* next; 
} typedef Node; 


Node* create(int v){
    Node* node = malloc(sizeof(*node));  
    node->next = NULL; 
    node->val = v; 

    return node; 
}

int insert_head(Node** head, Node* node){
    if(*head == NULL || node == NULL){
        return -1; 
    }
    node->next = *head;
    *head = node; 
    return 0;  
}

void print(Node* head){
    while(head->next != NULL){
        printf("(%d)", head->val);
        head = head->next;  
    }
}

int main(){
    printf("ergebnis: = %d \n", iterate(3, 10, &incr)); 
    return 0; 
}