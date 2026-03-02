// making binary tree using recursion
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
Node *makeTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    Node *temp = new Node(data);

    cout<<"enter the left child of "<<data<<endl;
    temp->left = makeTree();
    cout<<"enter the right child of "<<data<<endl;
    temp->right = makeTree();
}

void preOrder(Node *root){

    if(root==nullptr){
        return;
    } 
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root==nullptr){
        return;
    } 
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void postOrder(Node* root){
    if(root==nullptr){
        return;
    } 
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

int main()
{
    Node *root;
    root = makeTree();

        cout<<"preorder: ";
    preOrder(root);

        cout<<"inorder: ";
    inOrder(root);

        cout<<"postorder: ";
    postOrder(root);
}