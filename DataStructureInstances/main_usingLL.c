#include <stdio.h>
#include "linked_list.h"

int main() {
    Node *head = NULL;

    for (int i = 1; i <= 10; i++) {
        head = create_node(i, head);
    }

    Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}