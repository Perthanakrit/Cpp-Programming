#include <iostream>
#include "Node.h"
using namespace std;

void printList(Node *lst, int size);

int main(int argc, char const *argv[])
{
    Node *list = new Node[3];

    // for (int i = 0; i < 2; i++)
    // {
    //     list[i].setPos(i, i + 1);
    // }

    printList(list, 2);
    return 0;
}

void printList(Node *lst, int size)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        cout << lst->X() << ", " << lst->Y() << endl;
    }
}