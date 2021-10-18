#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **pointer, int n)
{
    struct node *newN;
    newN = malloc(sizeof(struct node));
    struct node *temp = *pointer;
    newN->data = n;
    newN->next = NULL;
    if (*pointer == NULL)
    {
        *pointer = newN;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newN;
    return;
}
void delete (struct node *del, int p)
{
    int cout = 0;
    struct node *temp;
    while (del != NULL)
    {
        cout++;
        if (cout == p)
            break;
        temp = del;
        del = del->next;
    }
    struct node *temp2 = del;
    del = del->next;
    temp->next = del;
    free(temp2);
}
void insertpos(struct node **ins, int p, int n)
{
    if (p < 1)
        printf("Position invalid ");
    else
    {
        while (p--)
        {
            if (p == 0)
            {
                struct node *newN;
                newN = malloc(sizeof(struct node));
                newN->data = n;
                newN->next = NULL;
                struct node *temp = newN;
                temp->next = *ins;
                *ins = temp;
            }
            //*ins=*ins->next
            ins = &(*ins)->next;
        }
    }
}
void printList(struct node *p)
{
    printf("Current list is : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    struct node *head = NULL;
    int option;
Start:
    printf("\nSelect option : 1.Insert in the end, 2.Insert in position, 3.Delete position ,4.Print, Press 0 to Exit\n");
    scanf("%d", &option);
    if (option == 1)
    {
        int value;
        printf("Enter the insert value : ");
        scanf("%d", &value);
        insert(&head, value);
        goto Start;
    }
    else if (option == 3)
    {
        int pos;
        printf("Enter delete position : ");
        scanf("%d", &pos);
        delete (head, pos);
        goto Start;
    }
    else if (option == 2)
    {
        int po, value;
        printf("ENter the position and value : ");
        scanf("%d%d", &po, &value);
        insertpos(&head, po, value);
        goto Start;
    }
    else if (option == 4)
    {
        printList(head);
        goto Start;
    }
    return 0;
}