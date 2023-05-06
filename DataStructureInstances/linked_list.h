#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    struct Node* next;
    int data;
};

void push(struct Node** head_ptr, int new_data);
void append(struct Node** head_ptr, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void deleteNode(struct Node** head_ptr, int key);
void printList(struct Node* node);

#endif