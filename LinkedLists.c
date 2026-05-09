#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printNode(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* tmp = head;

    while(head != NULL){

        tmp = head;
        head = head->next;
        free(tmp);
    }
}

Node* NodeSearch(Node* head, int target) {
    Node* current = head;
    while(current != NULL) {
        if(current->data == target) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int NodeDelete(Node** head, int target) {
    
    Node* prev = *head;
    Node* current = (*head)->next;

    while(current != NULL){
        if (current->data == target) {
            prev->next = current->next;
            free(current);
            return 1;
        }
        return 0;
    }
}

void NodeAppend(Node** head, int value) {
    Node* newNode = createNode(value);

    Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

int main () {

    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    NodeAppend(&head, 40);
    NodeDelete(&head, 20);
    printNode(head);
    Node* found = NodeSearch(head, 40);
    printf("Found value: %d\n", found->data);


    freeList(head);

    return 0;
}