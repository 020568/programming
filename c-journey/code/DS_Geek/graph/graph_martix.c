#include <stdio.h>
#include <stdlib.h>

/**
 * Function to create an adjacency matrix for a graph
 * @param V: Number of vertices
 * @param edges: 2D array representing the list of edges
 * @param edgeCount: Total number of edges in the edges array
 * @return: A pointer to the dynamically allocated 2D adjacency matrix
 */
int** createGraph(int V, int edges[][2], int edgeCount) {
    // 1. Allocate memory for the rows (array of pointers)
    int** mat = (int**)malloc(V * sizeof(int*));
    
    // 2. Allocate memory for each column and initialize with 0
    for (int i = 0; i < V; i++) {
        mat[i] = (int*)calloc(V, sizeof(int)); // calloc sets memory to zero automatically
    }

    // 3. Add each edge to the adjacency matrix
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        // Mark the connection between u and v
        mat[u][v] = 1;
        
        // Since the graph is undirected, also mark v and u
        mat[v][u] = 1; 
    }
    
    return mat;
}

int main() {
    int V = 3; // Number of vertices: 0, 1, 2

    // List of edges: {0, 1}, {0, 2}, {1, 2}
    int edges[][2] = {{0, 1}, {0, 2}, {1, 2}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    // Build the adjacency matrix
    int** mat = createGraph(V, edges, edgeCount);

    // Print the matrix
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < V; i++) 
	{
        for (int j = 0; j < V; j++) 
		{
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // --- Cleanup Memory ---
    for (int i = 0; i < V; i++) {
        free(mat[i]); // Free each row
    }
    free(mat); // Free the row pointers

    return 0;
}