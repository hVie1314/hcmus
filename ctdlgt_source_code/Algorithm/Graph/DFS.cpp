#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<vector<int>> graph, int start)
{
    vector<bool> visited(graph.size(), false);
    stack<int> s;

    s.push(start);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (!visited[current])
        {
            cout << current << " ";
            visited[current] = true;
        }

        for (int i = 0; i < graph[current].size(); ++i)
        {
            if (graph[current][i] != 0 && !visited[i])
            {
                s.push(i);
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
    DFS(graph, start);

    return 0;
}