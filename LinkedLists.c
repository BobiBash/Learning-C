#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

int node_count = 0;

Node* createNode(int value) {
    node_count++;
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

    
    Node* next = (*head)->next;
    Node* temp_current = *head;
    if((*head)->data == target) {
        *head = next;
        free(temp_current);
        node_count--;
        return 1;
    }
    
    Node* prev = *head;
    Node* current = (*head)->next;

    while(current != NULL){
        if (current->data == target) {
            prev->next = current->next;
            free(current);
            node_count--;
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

void NodeAppend(Node** head, int value) {
    Node* newNode = createNode(value);

    Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void NodeInsert(Node** head, int value, int index) {

    if (index == 0) {
        Node* newNode = createNode(value);
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    for(int i = 0; i < index - 1; i++) {
        if(current == NULL) {
            return;
        }
        current = current->next;
    }

    Node* newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;
}

int main () {

    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    NodeAppend(&head, 40);
    NodeDelete(&head, 20);
    Node* found = NodeSearch(head, 40);
    printf("Found value: %d\n", found->data);

    NodeInsert(&head, 45, 2);

    printNode(head);
    freeList(head);

    return 0;
}