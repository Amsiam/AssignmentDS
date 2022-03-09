#include <iostream>
using namespace std;

struct Node
{
    float data;
    Node *prev;
    Node *next;
};

void insertAtTheBegin(struct Node **start_ref, float data)
{
    struct Node *ptr1 = new Node;
    ptr1->data = data;
    ptr1->next = *start_ref;
    if (*start_ref != NULL)
        (*start_ref)->prev = ptr1;
    *start_ref = ptr1;
}

void printList(struct Node *start)
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(struct Node *start)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main()
{
    int size, i;

    cout << "Enter List Size :";
    cin >> size;
    float d;

    struct Node *start = NULL;

    cout << "Enter List Data :";
    for (i = 0; i < size; i++)
    {
        cin >> d;
        insertAtTheBegin(&start, d);
    }

    cout << "Linked list before sorting" << endl;
    printList(start);

    bubbleSort(start);

    cout << "Linked list after sorting " << endl;
    printList(start);

    return 0;
}
