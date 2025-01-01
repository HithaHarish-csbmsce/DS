#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void sortList(struct Node** head) {
    struct Node* i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node** head2) {
    struct Node* temp = *head1;
    if (temp == NULL) {
        *head1 = *head2;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = *head2;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    push(&list1, 3);
    push(&list1, 1);
    push(&list1, 7);
    push(&list1, 5);

    push(&list2, 4);
    push(&list2, 2);
    push(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    sortList(&list1);
    printf("Sorted List 1: ");
    printList(list1);

    reverseList(&list1);
    printf("Reversed List 1: ");
    printList(list1);

    concatenateLists(&list1, &list2);
    printf("Concatenated List: ");
    printList(list1);

    return 0;
}
OUTPUT:
List 1: 5 7 1 3
List 2: 6 2 4
Sorted List 1: 1 3 5 7
Reversed List 1: 7 5 3 1
Concatenated List: 7 5 3 1 6 2 4
