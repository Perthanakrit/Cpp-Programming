#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *prev;
    struct node *next;
} Node;

Node *create_node(int data);
void insert_node(Node **head, int number);
void delete_node(Node **head, int number);
void sorted_list(Node **head);
void print_all_nodes(Node *head);

int main()
{
    Node *list = NULL;
    int i, n = 10, num = 0;
    char input[n];
    char action;

    while (1)
    {
        printf("input> ");
        fgets(input, n, stdin);
        action = input[0];

        if (action == 'q')
            break;

        if (action == 'p')
        {
            print_all_nodes(list);
            continue;
        }
        num = atoi(input + 2);

        switch (action)
        {
        case 'i':
            insert_node(&list, num);
            break;
        case 'd':
            delete_node(&list, num);
            break;
        default:
            break;
        }

        // input[0] = '\0';
    }

    return 0;
}

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->number = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node **head, int number)
{
    Node *new_node = create_node(number);
    // Empty list
    if (*head == NULL)
    {
        *head = new_node;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return;
    }

    // Non-empty list
    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    new_node->next = NULL;

    sorted_list(head);
}

void sorted_list(Node **head)
{
    Node *current = *head;
    Node *next_node = NULL;
    int temp;

    if (*head == NULL)
    {
        return;
    }

    while (current != NULL)
    {
        next_node = current->next;

        while (next_node != NULL)
        {
            if (current->number > next_node->number)
            {
                temp = current->number;
                current->number = next_node->number;
                next_node->number = temp;
            }
            next_node = next_node->next;
        }
        current = current->next;
    }
}

void print_all_nodes(Node *head)
{
    Node *current = head;
    printf("[ ");
    while (current != NULL)
    {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("]\n");
}

void delete_node(Node **head, int number)
{
    Node *current = *head;
    Node *prevNode = NULL;

    while (current != NULL)
    {
        if (current->number == number)
        {
            // First node
            if (prevNode == NULL)
            {
                *head = current->next;
                free(current);
                if (*head == NULL)
                {
                    return;
                }
            }
            else
            {
                prevNode->next = current->next;
                free(current);
            }
            current = prevNode->next;
        }
        else
        {
            prevNode = current;
            current = current->next;
        }
    }
}