#include<iostream>
#include<stack>
#include<omp.h>
#include<vector>

using namespace std;

const int MAX = 1000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node)
{
    stack<int> s;
    s.push(node);

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        if (!visited[curr])
        {
            visited[curr] = true;
            cout << curr << " ";
        }
        #pragma omp parallel for
        for (int i = 0; i < graph[curr].size(); i++)
        {
            int adj = graph[curr][i];
            if (!visited[adj])
            {
                s.push(adj);
            }
        }
    }
}

int main()
{
    int n, m, start_node;
    cout << "Enter the number of nodes, number of edges, and the starting node of the graph: \n";
    cin >> n >> m >> start_node;
    cout << "Enter pairs of nodes and edges: \n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    dfs(start_node);

    return 0;
}
