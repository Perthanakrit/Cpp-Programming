#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *prev;
    struct node *next;
} Node;

int main()
{
    void insert_node(Node * head, int number);
    void delete_node(Node * head, int number);
    void sorted_list(Node * head);
    void print_all_nodes(Node * head);

    return 0;
}
