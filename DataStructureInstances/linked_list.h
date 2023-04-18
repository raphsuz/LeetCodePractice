#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data, Node *next);

#endif // LINKED_LIST_H