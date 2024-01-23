#include <iostream>
#include <queue>

using namespace std;

#define MAX_NODES 100 // Maximum number of nodes in the graph

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix to represent the graph
bool visited[MAX_NODES]; // Array to keep track of visited nodes

void bfs(int start, int numNodes) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < numNodes; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int numNodes = 7; // Number of nodes in the graph

    // Adjacency matrix representation of the graph
    int adjMatrix[7][7] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}
    };

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = adjMatrix[i][j];
        }
    }

    cout << "BFS Traversal: ";
    bfs(0, numNodes); // Start BFS traversal from node 0

    return 0;
}
