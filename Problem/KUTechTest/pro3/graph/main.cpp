#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

#define MAX_V 100

typedef struct __node
{
    double x;
    double y;
    list<int> adj;
} Node;

class WeightedGraph
{

private:
    double adjMatrix[MAX_V][MAX_V];

public:
    int V;

    WeightedGraph(int V)
    {
        this->V = V;
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, double weight)
    {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    int minDistance(double dist[], bool sptSet[])
    {
        // Initialize min value
        int min_index;
        double min = INT_MAX;

        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v],
                min_index = v;

        return min_index;
    }

    // -- Souce: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    void dijkstra(int src, int end)
    {
        src--;
        end--;
        double dist[V];

        bool sptSet[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < V - 1; count++)
        {

            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < V; v++)
                if (!sptSet[v] && this->adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + this->adjMatrix[u][v] < dist[v])
                    dist[v] = dist[u] + this->adjMatrix[u][v];
        }
    }
    // --
};

double calculateDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int n = 0, u, v, i, begin, end;
    char input[100];
    char *arr = NULL;
    double x, y;
    Node *nodes;

    cin >> n >> ws;

    WeightedGraph g(n);
    nodes = new Node[n];

    // Input
    for (u = 0; u < n; u++)
    {
        cin >> x >> y;

        cin.getline(input, 100);
        arr = strtok(input, " ");
        i = 0;

        while (arr != NULL)
        {
            v = atoi(arr);
            nodes[u].x = x;
            nodes[u].y = y;
            nodes[u].adj.push_back(v - 1);
            arr = strtok(NULL, " ");
            i++;
        }
    }

    cin >> begin >> end;

    for (i = 0; i < n; i++)
    {
        for (list<int>::iterator it = nodes[i].adj.begin(); it != nodes[i].adj.end(); it++)
        {
            g.addEdge(i, *it, calculateDistance(nodes[i].x, nodes[i].y, nodes[*it].x, nodes[*it].y));
        }
    }

    g.dijkstra(begin, end);

    return 0;
}