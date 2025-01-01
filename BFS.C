#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;
    
    printf("BFS Traversal: ");
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start, graph[MAX][MAX];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    
    bfs(graph, n, start);
    return 0;
}
OUTPUT:
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 1 0
0 1 1 0 0
0 1 0 0 0
Enter starting vertex: 0
BFS Traversal: 0 1 2 3 4
