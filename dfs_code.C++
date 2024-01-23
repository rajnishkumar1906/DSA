#include <iostream>
#include <stack>

using namespace std;

#define MAX_NODES 100 // Maximum number of nodes in the graph

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix to represent the graph
bool visited[MAX_NODES]; // Array to keep track of visited nodes

void dfs(int start, int numNodes) {
    stack<int> s;

    visited[start] = true;
    s.push(start);
    cout << start << " ";

    while (!s.empty()) {
        int current = s.top();
        bool found = false;

        for (int i = 0; i < numNodes; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                s.push(i);
                cout << i << " ";
                found = true;
                break;
            }
        }

        if (!found) {
            s.pop();
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

    cout << "DFS Traversal: ";
    dfs(0, numNodes); // Start DFS traversal from node 0

    return 0;
}
