#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Stack implementation
struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void printStack(struct Stack* stack) {
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Queue implementation
struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* queue, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void printQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack = {NULL};
    struct Queue queue = {NULL, NULL};

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Stack after pushes: ");
    printStack(&stack);

    printf("Popped from stack: %d\n", pop(&stack));
    printf("Stack after pop: ");
    printStack(&stack);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("Queue after enqueues: ");
    printQueue(&queue);

    printf("Dequeued from queue: %d\n", dequeue(&queue));
    printf("Queue after dequeue: ");
    printQueue(&queue);

    return 0;
}

OUTPUT:
Stack after pushes: 30 20 10
Popped from stack: 30
Stack after pop: 20 10
Queue after enqueues: 1 2 3
Dequeued from queue: 1
Queue after dequeue: 2 3
