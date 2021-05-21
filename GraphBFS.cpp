#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
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
        if (u != v)
        {
            adj[u].push_back(v);
        }
    }
    void BFS(int src)
    {
        bool *visited = new bool[val];
        memset(visited, false, val); // Initialize the visited list as false as none of the vertices is visited

        list<int> q;
        visited[src] = true;
        q.push_back(src); // Insert the source vertex and mark it as visited --> True

        list<int>::iterator it;

        while (!q.empty())
        {
            src = q.front();
            cout << src;
            q.pop_front();
            for (it = adj[src].begin(); it != adj[src].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    q.push_back(*it);
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(3, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 4);
    g.addEdge(4, 0);
    g.BFS(1);
    return 0;
}