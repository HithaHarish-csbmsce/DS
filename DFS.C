#include <stdio.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int n, int visited[MAX], int vertex) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, n, visited, i);
        }
    }
}

int isConnected(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};
    dfs(graph, n, visited, 0);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, graph[MAX][MAX];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    if (isConnected(graph, n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }
    
    return 0;
}
OUTPUT:
Enter number of vertices: 5
Enter adjacency matrix:
0 1 0 0 0
1 0 1 1 0
0 1 0 0 1
0 1 0 0 0
0 0 1 0 0
The graph is not connected.

Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
The graph is connected.
