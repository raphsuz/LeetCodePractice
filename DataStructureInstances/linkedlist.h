#include <stdlib.h>

struct Node {
    struct Node* next;
    int data;
};

// Using the pointer of the head_ptr could prevent the problem from modify the value by accident
void appendToTail(struct Node** head_ptr, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head_ptr == NULL) {
        *head_ptr = new_node;
    } else {
        struct Node* current = *head_ptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
