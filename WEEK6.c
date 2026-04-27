#include <stdio.h>
#include <limits.h> // For INT_MAX

int main1() {
    int n, i, j, count;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int dist[n];
    int visited[n];

    // Input adjacency matrix
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0 && i != j) {
                graph[i][j] = INT_MAX; // No edge
            }
        }
    }

    int start;
    printf("Enter the starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    // Initialize distances and visited array
    for(i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;

    // Dijkstra's algorithm
    for(count = 0; count < n-1; count++) {
        int min = INT_MAX, u = -1;

        // Find the vertex with minimum distance from unvisited vertices
        for(i = 0; i < n; i++) {
            if(!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break; // All remaining vertices are unreachable

        visited[u] = 1; // Mark the picked vertex as visited

        // Update dist value of the adjacent vertices
        for(i = 0; i < n; i++) {
            if(!visited[i] && graph[u][i] != INT_MAX && dist[u] != INT_MAX
               && dist[u] + graph[u][i] < dist[i]) {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    // Print the results
    printf("Vertex \t Distance from Source\n");
    for(i = 0; i < n; i++) {
        if(dist[i] == INT_MAX) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }

    return 0;
}
