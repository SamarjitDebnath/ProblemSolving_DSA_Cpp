#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int val;
    list<int> *adj;

public:
    Graph(int x)
    {
        val = x;
        adj = new list<int>[val];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void DFS(int src)
    {
        bool *visited = new bool[val];
        memset(visited, false, val);

        list<int> s;
        visited[src] = true;
        s.push_front(src);

        list<int>::iterator it;

        while (!s.empty())
        {
            src = s.front();
            cout << src << " ";
            s.pop_front();
            for (it = adj[src].begin(); it != adj[src].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    s.push_front(*it);
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 0) \n";
    g.DFS(0);

    return 0;
}
