#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

#define MAX 100

typedef struct __node
{
    double x;
    double y;
    list<int> adj;
} Node;

const int MAX_V = 100; // Maximum number of vertices

class WeightedGraph
{

private:
    double adjMatrix[MAX_V][MAX_V];
    void printSolution(double dist[], int end)
    {
        printf("Vertex \t\t Distance from Source\n");
        for (int i = 0; i < V; i++)
            if (i == end)
                printf("%d \t\t %lf\n", i, dist[i]);
    }

public:
    int V; // Number of vertices
    // Adjacency matrix to store weights

    WeightedGraph(int V)
    {
        this->V = V;
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = 0; // Initialize all elements to 0 (no edge)
            }
        }
    }

    void addEdge(int u, int v, double weight)
    {
        // Add edge from u to v with specified weight
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }

    // void findMinDistance(int begin, int end)
    // {
    //     vector<bool> visited(this->V, false);
    //     queue<int> q;

    //     q.push(start);
    //     visited[start] = true;

    //     int distance = 0; // To keep track of total distance traversed
    //     int current = 0;  // To keep track of current vertex
    //     while (!q.empty())
    //     {
    //         current = q.front();
    //         q.pop();

    //         // Check if we reached the end vertex
    //         if (current == end)
    //         {
    //             break; // Minimum distance found, exit loop
    //         }

    //         // Explore unvisited neighbors
    //         for (auto neighbor : this->adjMatrix[current])
    //         {
    //             double weight = neighbor;
    //             double next = neighbor;
    //             if (!visited[next])
    //             {
    //                 visited[next] = true;
    //                 q.push(next);
    //                 distance += weight; // Update distance
    //             }
    //         }
    //     }

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

    void dijkstra(int src, int end)
    {
        src--;
        end--;
        double dist[V]; // The output array.  dist[i] will hold the
                        // shortest
        // distance from src to i

        bool sptSet[V]; // sptSet[i] will be true if vertex i is
                        // included in shortest
        // path tree or shortest distance from src to i is
        // finalized

        // Initialize all distances as INFINITE and stpSet[] as
        // false
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < V - 1; count++)
        {
            // Pick the minimum distance vertex from the set of
            // vertices not yet processed. u is always equal to
            // src in the first iteration.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the
            // picked vertex.
            for (int v = 0; v < V; v++)

                // Update dist[v] only if is not in sptSet,
                // there is an edge from u to v, and total
                // weight of path from src to  v through u is
                // smaller than current value of dist[v]
                if (!sptSet[v] && this->adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + this->adjMatrix[u][v] < dist[v])
                    dist[v] = dist[u] + this->adjMatrix[u][v];
        }

        // print the constructed distance array
        printSolution(dist, end);
    }

    // Function to print the graph (adjacency matrix)
    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                printf("%0.2f ", adjMatrix[i][j]);
            }
            std::cout << "\n";
        }
    }
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

    g.printGraph();

    g.dijkstra(begin, end);

    return 0;
}
