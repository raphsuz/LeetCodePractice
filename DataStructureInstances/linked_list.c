#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void push(struct Node** head_ptr, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ptr);
    (*head_ptr) = new_node;
}

void append(struct Node** head_ptr, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ptr == NULL) {
        *head_ptr = new_node;
    } else {
        struct Node* last = *head_ptr;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(struct Node** head_ptr, int key) {
    struct Node* temp = *head_ptr;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ptr = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The given key is not present in the list");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
