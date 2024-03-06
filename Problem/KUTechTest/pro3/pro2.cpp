#include <iostream>
using namespace std;

typedef struct __pos
{
    int x;
    int y;
} Position;

typedef struct __node
{
    Position point;
    struct __node **nodes;
} Node;

int main()
{
    int n, i;
    cin >> n;
    Node *points = (Node *)malloc(sizeof(Node) * n);

    for (i = 0; i < n; i++)
    {
        cin >> points[i].point.x >> points[i].point.y;
    }

    for (i = 0; i < n; i++)
    {
        cout << points[i].point.x << ", " << points[i].point.y << endl;
    }

    return 0;
}