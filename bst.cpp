#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    Node *l;
    Node *r;
    Node(int d)
    {
        data = d;
        l = r = NULL;
    }
} Node;

Node *insertBST(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);

    if (root->data > data)
        root->l = insertBST(root->l, data);
    else
        root->r = insertBST(root->r, data);

    return root;
}

int search(Node *root, int key)
{
    if (root == NULL)
        return -1;
    if (root->data == key)
        return 1;

    if (root->data > key)
        return search(root->l, key);
    else
        return search(root->r, key);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
}

int main()
{
    Node *root = NULL;
    cout << "Enter How many element do you want: ";
    int a;
    cin >> a;
    int v;
    cout << "Enter Elements: ";
    cin >> v;

    root = insertBST(root, v);

    for (int i = 0; i < a - 1; i++)
    {
        cin >> v;
        insertBST(root, v);
    }
    int key;
    cout << "Enter Key: ";
    cin >> key;
    if (search(root, key) != -1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}