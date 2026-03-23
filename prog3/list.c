#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val; 
    struct Node* next; 
} typedef Node;


Node* create(int v){
    Node* n = malloc(sizeof(Node));
    n->next = NULL; 
    n->val = v; 

    return n;
}

int insert_head(Node** head, Node* new_head){
    
    // irgendwas bei der Werten läuft nicht 
    if ( head == NULL || new_head == NULL){ return -1;}
    
    // liste ist leer 
    if (*head == NULL){
        *head = new_head;
        return 0;  
    }

    // es gibt bereits eine liste  

    new_head->next = *head; 
    *head = new_head; 

    return 0; 
}

void print(Node* list){
    while (list != NULL){
        printf("%d", list->val); 
        list = list->next; 
    }
}


int main(){
    Node* head = NULL; /* leere Liste */
    int error = insert_head(&head, create(5));
    error |= insert_head(&head, create(3));
    error |= insert_head(&head, create(1));
    if (error != 0) {
    printf("Fehler\n");
    } else {
    print(head); /* Gewünschte Ausgabe: 1 3 5 */
    }
    return 0;
}

