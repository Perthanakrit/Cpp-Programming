#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;
    Node *tail;
    int size;

    Node *createNode(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sort()
    {
        // bubble sort
        Node *i, *j;
        bool swapped = false;

        for (i = head; i->next != NULL; i = i->next)
        {
            for (j = head; j->next != NULL; j = j->next)
            {
                if (j->data > j->next->data)
                {
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                    swapped = true;
                }
            }

            if (!swapped)
            {
                break;
            }
        }
    }

    void insert(int data)
    {
        Node *newNode = createNode(data);

        // if list is empty
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else // if list is not empty
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void update(int index, int data)
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        Node *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        curr->data = data;
    }
};

int main()
{
    LinkedList *list = new LinkedList();

    list->insert(30);
    list->insert(10);
    list->insert(20);

    list->print();

    list->sort();

    list->print();

    return 0;
}