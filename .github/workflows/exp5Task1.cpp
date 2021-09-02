#include <stdlib.h>

#include <iostream>
using namespace std;

// Creating the node
struct Node
{
    int data;
    struct Node *next;
    struct Node*prev;
};

void insertStart(struct Node **headRef, int newData)
{
    // Allocating memory to the node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // inserting new data in the node
    newNode->data = newData;
    newNode->next = (*headRef);
        
    if ((*headRef) != NULL)
    (*headRef)->prev = newNode;
    // Move head to new node
    (*headRef) = newNode;
}

// Insert a node after a node
void insertMiddle(struct Node *preNOde, int newData)
{
    if (preNOde == NULL)
    {
        cout << "the previous node cannot be NULL";
        return;
    }
//allocating a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = preNOde->next;
    preNOde->next = newNode;
    newNode->prev = preNOde;
     if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

// Inserting a node at the end
void insertEnd(struct Node **headRef, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *headRef;

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        newNode->prev = NULL;
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode -> prev = last;
    return;
}

// Deleting a particualr node
void deleteNode(struct Node **headRef, int key)
{
    struct Node *temp = *headRef, *prev;

    if (temp != NULL && temp->data == key)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL)
        return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}
// Searching a node
bool searchNode(struct Node **headRef, int key)
{
    struct Node *current = *headRef;

    while (current != NULL)
    {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

// Printing the linked list
void printLinkList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
}

// Driver program
int main()
{
    struct Node *head = NULL;

    insertStart(&head, 1);
    insertStart(&head, 7);
    insertEnd(&head, 5);
    insertEnd(&head, 2);
    insertMiddle(head->next, 3);
    insertMiddle(head->next, 4);
    insertMiddle(head->next, 5);

    cout << "The Double Linked list: ";
    printLinkList(head);

    cout << "\nDouble Linked list after deleting an element: ";
    deleteNode(&head, 4);
    printLinkList(head);

    int findItem= 3;
    if (searchNode(&head, findItem))
    {
        cout << endl
             << findItem<< " is found";
    }
    else
    {
        cout << endl
             << findItem<< " is not found";
    }

    cout << "\n DoubleLinked List: ";
    printLinkList(head);
}
