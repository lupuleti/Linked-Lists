# include <iostream>
# include <cstdlib>

using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
int count_nodes = 0;
struct node *head = NULL;
struct node *tail = NULL;

// Function to insert at the begin of a list.
void insert_begin (int info)
{
    // Set Data;
    struct node *data_node;
    data_node = new struct node;
    data_node -> info = info;

    // Link to the start of the list.
    if (head == NULL)
    {
        count_nodes++;
        data_node->next = NULL;
        data_node->prev = NULL;
        head = data_node;
        tail = data_node;
    }
    else
    {
        count_nodes++;
        data_node->prev = NULL;
        data_node->next = head;
        head->prev = data_node;
        head = data_node;
    }
}

// Function to insert at the end of a list.
void insert_end (int info)
{
    // Set Data;
    struct node *data_node;
    data_node = new struct node;
    data_node -> info = info;

    // Link to the start of the list.
    if (tail == NULL)
    {
        count_nodes++;
        data_node->next = NULL;
        data_node->prev = NULL;
        head = data_node;
        tail = data_node;
    }
    else
    {
        count_nodes++;
        tail->next = data_node;
        data_node->prev = tail;
        data_node->next = NULL;
        tail = data_node;
    }
}

void print_list(struct node *head)
{
    if (head != NULL)
    {
        cout << head->info;
        int a = head->info;
        print_list(head->next);
        cout << a;
    }
}

// Function to insert at a given position.
void insert_at_pos (int pos, int info)
{
    // Set Data;
    struct node *data_node;
    data_node = new struct node;
    data_node -> info = info;

    int count = 1;
    struct node *node_replaced;

    // Make sure the given position exists in the list:
    if(pos > count_nodes)
    {
        cout << "That position doesn't exist in the list.";
    }
    else
    {
        // Check whether to iterate from head or tail:
        if (pos - 1 < count_nodes - pos)
        {
            node_replaced = head;
            // Get to the searched node:
            while (count <= pos - 1)
            {
              node_replaced = node_replaced->next;
              count++;
            }
       }
        else
        {
            node_replaced = tail;
            // Get to the searched node:
            while (count <= count_nodes - pos)
            {
                node_replaced = node_replaced->prev;
                count++;
            }
        }

        // Insert the data_node into the found place.
        count_nodes++;
        data_node->prev = node_replaced->prev;
        data_node->next = node_replaced;
        node_replaced->prev = data_node;
        data_node->prev->next = data_node;


    }

}

// Function to delete a given position.
void delete_pos (int pos)
{

    int count = 1;
    struct node *node_replaced;

    // Make sure the given position exists in the list:
    if(pos > count_nodes)
    {
        cout << "That position doesn't exist in the list.";
    }
    else
    {
        // Check whether to iterate from head or tail:
        if (pos - 1 < count_nodes - pos)
        {
            node_replaced = head;
            // Get to the searched node:
            while (count <= pos - 1)
            {
              node_replaced = node_replaced->next;
              count++;
            }
       }
        else
        {
            node_replaced = tail;
            // Get to the searched node:
            while (count <= count_nodes - pos)
            {
                node_replaced = node_replaced->prev;
                count++;
            }
        }

        // Insert the data_node into the found place.
            count_nodes--;
            node_replaced->prev->next = node_replaced->next;
            node_replaced->next->prev = node_replaced->prev;
            delete node_replaced;
    }

}
int main()
{
    //list = new struct node;
    insert_begin(1);
    insert_end(5);
    insert_begin(2);
    insert_end(8);
    insert_begin(3);
    insert_begin(4);
    insert_begin(5);
    insert_at_pos(5,121);
    delete_pos(7);

    while (head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
    while (tail != NULL)
    {
        cout << tail->info << " ";
        tail = tail->prev;
    }

}


