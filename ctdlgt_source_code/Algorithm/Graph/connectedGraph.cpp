#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> graph;

void BFS(vector<bool>& visited, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); ++i)
        {
            if (graph[current][i] != 0 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int countConnectedComponent(vector<bool>& visited)
{
    int count = 0;

    for (int i = 0; i < graph.size(); ++i)
    {
        if (!visited[i])
        {
            ++count;
            BFS(visited, i);
        }
    }
    return count;
}

// vector<vector<int>> toAdjacencyMatrix(vector<pair<int, int>> edges, int verticest)
// {
//     vector<vector<int>> graph(verticest, vector<int>(verticest, 0));

//     for (vector<pair<int, int>>::iterator it = edges.begin(); it != edges.end(); ++it)
//     {
//         int i = it->first - 1; 
//         int j = it->second - 1;
//         graph[i][j] = 1;
//         graph[j][i] = 1; // remove this line if graph is directed
//     }
//     return graph;
// }

std::vector<std::vector<int>> toAdjacencyMatrix(vector<pair<int, int>> edges, int verticest) {
    std::vector<std::vector<int>> adjMatrix(verticest, std::vector<int>(verticest, 0));

    for (vector<pair<int, int>>::iterator it = edges.begin(); it != edges.end(); ++it) {
        int u = it->first - 1; // Adjust for 0-based indexing
        int v = it->second - 1; // Adjust for 0-based indexing
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // If it's an undirected graph
    }

    return adjMatrix;
}

vector<pair<int, int>> input(int& verticest)
{
    int n = 0; // number of vertices
    int m = 0; // number of edges
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }
    return edges;
}

void printGraph(const vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int verticest = 0;
    vector<bool> visited = vector<bool>(graph.size(), false);
    vector<pair<int, int>> edges = input(verticest);
    graph = toAdjacencyMatrix(edges, verticest);
    
    // connected graph
    // graph = {
    //     {0, 1, 1, 0, 0},
    //     {1, 0, 0, 1, 0},
    //     {1, 0, 0, 1, 1},
    //     {0, 1, 1, 0, 1},
    //     {0, 0, 1, 1, 0}
    // };


    printGraph(graph);

    // not connected graph
    // graph = {
    // {0, 1, 1, 0, 0},
    // {1, 0, 1, 0, 0},
    // {1, 1, 0, 0, 0},
    // {0, 0, 0, 0, 1},
    // {0, 0, 0, 1, 0}
    // };

    int connectedComponent = countConnectedComponent(visited);

    if (connectedComponent == 1)
        cout << "Graph is connected" << endl;
    else
        cout << "Graph is not connected" << endl;

    return 0;
} 