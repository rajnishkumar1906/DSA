/*
Problem Statement
Sanju loves graph theory and has recently started learning about
Breadth-First Search (BFS) algorithms.
He is given a directed graph represented as an adjacency matrix, and
he wants to implement the BFS algorithm to traverse the graph starting from a given vertex.


        Input Format

The first line of input consists of the two integers, V and E,
separated by a space, representing the number of vertices and edges in the network, respectively.
The next E lines consist of two integers,
u and v, separated by a space, representing an edge between vertex u and vertex v.


        Output Format

The output displays a single line containing the vertices visited
during the BFS traversal, separated by a space.


         Sample Input
5 4
0 1
0 2
0 3
2 4

         Sample Output
0 1 2 3 4
*/

#include <iostream>
#include <queue>

#define MAX_V 100

using namespace std;
void enqueue(queue<int> &queue, int vertex)
{
    queue.push(vertex);
}

int dequeue(queue<int> &queue)
{
    int front = queue.front();
    queue.pop();
    return front;
}

void BFS(int V, int adjList[MAX_V][MAX_V])
{
    int visited[MAX_V] = {0};
    queue<int> queue;

    int startVertex = 0;
    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!queue.empty())
    {
        int currVertex = dequeue(queue);

        cout << currVertex << " ";

        for (int i = 0; i < V; ++i)
        {
            if (adjList[currVertex][i] == 1 && visited[i] == 0)
            {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    int adjList[MAX_V][MAX_V] = {0};

    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
    }
    BFS(V, adjList);
    return 0;
}
