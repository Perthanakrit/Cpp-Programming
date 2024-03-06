#include <iostream>
// #include <cstdlib>
using namespace std;

#define MAX 100

typedef struct __node
{
    double x;
    double y;
} Node;

class Graph
{

public:
    int V;                   // Number of vertices
    int adjMatrix[MAX][MAX]; // Matrix to store edges
    Node *nodes;

    Graph(int V)
    {
        this->V = V;
        nodes = new Node[V];
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = 0; // Initialize all elements to 0 (no edge)
            }
        }
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1; // Add edge from u to
        adjMatrix[v][u] = 1;
    }

    double distance(Node a, Node b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    double findRouteMinDistance(int start, int end)
    {
        double minDistance = 0;
        double distance = 0;
        int i = start;
        int j = end;
        while (i != j)
        {
            distance = this->distance(nodes[i], nodes[j]);
            minDistance += distance;
            i = j;
            j = end;
        }
        return minDistance;
    }

    // Function to print the graph
    void printGraph()
    {
        cout << "    ";
        for (int i = 0; i < V; ++i)
        {
            cout << i + 1 << " ";
        }
        cout << "\n";
        cout << "    ------" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << i + 1 << " | ";
            for (int j = 0; j < V; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

private:
    double routeDistance(int start, int end)
    {
        double distance = 0;
        distance = this->distance(nodes[start], nodes[end]);
        return distance;
    }
};

void printNodes(Node *nodes, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i + 1 << ": (" << nodes[i].x << ", " << nodes[i].y << ")" << endl;
    }
}

int main()
{
    int n = 0, u, v, i;
    char input[100];
    char *arr = NULL;
    double x, y;

    cin >> n >> ws;
    Graph g(n); // Create a graph with 4 vertices

    for (u = 0; u <= n; u++)
    {
        cin >> x >> y;
        g.nodes[u].x = x;
        g.nodes[u].y = y;

        cin.getline(input, 100);
        arr = strtok(input, " ");
        i = 0;

        while (arr != NULL)
        {
            v = atoi(arr);
            g.addEdge(u, v - 1);
            arr = strtok(NULL, " ");
            i++;
        }
    }

    g.printGraph();
    puts("");
    printNodes(g.nodes, n);

    return 0;
}
