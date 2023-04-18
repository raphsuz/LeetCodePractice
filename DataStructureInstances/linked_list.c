#include "linked_list.h"
#include <stdlib.h>

Node *create_node(int data, Node *next) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}