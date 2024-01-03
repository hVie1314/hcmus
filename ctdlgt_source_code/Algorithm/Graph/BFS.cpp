#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> graph, int start)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";
        
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

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int start = 0;
    BFS(graph, start);

    return 0;
}

