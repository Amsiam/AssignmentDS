#include<iostream>

using namespace std;


typedef struct Node
{
    int data;
    Node* l;
    Node* r;
    Node(int d){
        data = d;
        l=r=NULL;
    }
} Node;

Node* insertBST(Node *root, int data){
    if(root==NULL)return new Node(data);

    if(root->data>data)root->l = insertBST(root->l,data);
    else root->r = insertBST(root->r,data);
    
    return root;
}

void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}


int main(){
    Node *root=NULL;

    root = insertBST(root,50);
    insertBST(root,50);
    insertBST(root,43);
    insertBST(root,64);
    insertBST(root,32);
    insertBST(root,43);
    insertBST(root,46);
    inorder(root);
    cout<<endl;

    return 0;
}