#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class Graph
{
private:
    int val;
    int graph[MAX][MAX];

    // Graph Constructor
public:
    Graph(int x)
    {
        val = x;
        // Intialize the adjacency matrix by 0 as no vertices are connected
        for (int i = 0; i < val; i++)
        {
            for (int j = 0; j < val; j++)
            {
                graph[i][j] = 0;
            }
        }
    }
    void display()
    {
        cout << "\nThe Adjacency Matrix of the Graph is:" << endl;
        for (int i = 0; i < val; i++)
        {
            cout << endl;
            for (int j = 0; j < val; j++)
            {
                cout << " " << graph[i][j];
            }
        }
    }
    void addEgde(int x, int y)
    {
        // Check if vertices are present there or not
        if ((x >= val) || (y > val))
            cout << "Vertex Not Found!";
        // Check if vertices are same or not
        if (x == y)
            cout << "Same Vertex";
        // Assign 1 to the the vertices
        else
        {
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
    }
    void addVertex()
    {
        // Increase the val
        val++;
        for (int i = 0; i < val; ++i)
        {
            graph[i][val - 1] = 0;
            graph[val - 1][i] = 0;
        }
    }
    void removeVertex(int x)
    {
    	// Check if the vertices are present there or not
        if (x > val)
            cout << "Vertex Not Present Nothing to delete";
        else
        {
            int i;
            // Iterate till x < val
            while (x < val)
            {
            	// Subsitute the column with its preceding one 
                for (i = 0; i < val; ++i)
                {
                    graph[i][x] = graph[i][x + 1];
                    // graph[x][i] = graph[x + 1][i];  ----> This will give an wrong result
                }
                // Subsitute the row with its preceding one
                for (i = 0; i < val; ++i)
                {
                    graph[x][i] = graph[x + 1][i];
                }
                x++;
            }
            val--;
        }
    }
};

int main()
{
    Graph g(5);
    g.display();
    g.addEgde(1, 2);
    g.addEgde(3, 4);
    g.addEgde(0, 4);
    g.display();
    g.addVertex();
    g.display();
    g.removeVertex(2);
    g.display();
    return 0;
}
