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

// Inorder traversal (Left -> Root -> Right): gives sorted output for BST
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    
    inorderTraversal(root->left);      // Traverse left subtree
    cout << root->data << " ";         // Print current node
    inorderTraversal(root->right);     // Traverse right subtree
}

// Preorder traversal (Root -> Left -> Right)
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    
    cout << root->data << " ";         // Print current node
    preorderTraversal(root->left);     // Traverse left subtree
    preorderTraversal(root->right);    // Traverse right subtree
}

// Postorder traversal (Left -> Right -> Root)
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    
    postorderTraversal(root->left);    // Traverse left subtree
    postorderTraversal(root->right);   // Traverse right subtree
    cout << root->data << " ";         // Print current node
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
    
    // Display the tree using different traversal methods
    cout << "Inorder Traversal (Sorted): ";
    inorderTraversal(root);
    cout << "\n";
    
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";
    
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";
    
    return 0;
}

/*
Tree Structure formed from array: {11, 2, 4, 5, 8, 3, 5, 20, 30, 43, 54, 56, 3, 34}

                            10 (root)
                           /  \
                          2    11
                           \      \
                            4     20
                           / \      \
                          3   5     30
                           \  / \     \
                            3 5  8    43
                                /    / \
                               5   34  54
                                        \
                                        56

Inorder (Left-Root-Right):   2 3 3 4 5 5 5 8 10 11 20 30 34 43 54 56
Preorder (Root-Left-Right):  10 2 4 3 3 5 5 8 11 20 30 43 34 54 56
Postorder (Left-Right-Root): 3 3 4 5 5 8 2 11 20 30 34 54 56 43 10

Note: Duplicate values are inserted to the right subtree (using >= comparison)
*/

/*

10
   \
    20
       \
        40
       /  \
     33    60
    /
   31

*/