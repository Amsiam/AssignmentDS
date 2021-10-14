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
    cout << "Inorder Traversal: " << endl;
    inorder(root);
    cout << endl;

    return 0;
}