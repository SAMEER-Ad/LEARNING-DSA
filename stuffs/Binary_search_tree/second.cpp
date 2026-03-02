// Binary Search Tree Implementation with insertion and traversal
#include <iostream>
#include <stdlib.h>
using namespace std;

// Node class to represent each node in the BST
class Node
{
public:
    int data;
    Node *right, *left;
    
    // Constructor to initialize a new node
    Node(int data)
    {
        this->data = data;
        right = left = nullptr;
    }
};

// Function to insert a value into the BST
Node *insert(Node *root, int value)
{
    // Base case: if root is null, create a new node
    if (root == nullptr)
    {
        Node *temp = new Node(value);
        return temp;
    }

    // If value is less than current node, insert into left subtree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    // Otherwise, insert into right subtree
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    
    postorderTraversal(root->left);    // Traverse left subtree
    postorderTraversal(root->right);   // Traverse right subtree
    cout << root->data << " ";         // Print current node
}
bool search(Node* root,int target){
    if(root==nullptr){
        return 0;
    }
    if(target==root->data){
        return 1;

    }

    if(root->data>target){
        return search(root->left,target);
    }
    else if(root->data<=target){
        return search(root->right,target);
    }
}
int main()
{
    // Create root node with value 10
    Node *root = new Node(10);

    // Array of values to insert into the BST
    int arr[] = {11, 2, 4, 5, 8, 3, 5, 20, 30, 43, 54, 56, 3, 34};
    
    // Insert all elements from the array into the BST
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        root = insert(root, arr[i]);  // FIXED: Assign result back to root
    }
    int x;
    cout<<"Enter elements to search: ";
    cin>>x;

    if(search(root,x)){
        cout<<"element found"<<endl;
    }else{
        cout<<"element didnt found"<<endl;
    }
    

    

    
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";
    
    return 0;
}
