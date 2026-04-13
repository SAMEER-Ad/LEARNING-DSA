#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left, *right;
    node(int value){
        data = value;
        left = right = nullptr;
    }
};

node* insert(node* root, int target){
    if(!root){
        node* temp = new node(target);
        return temp;
    }
    if(target < root->data){
        root->left = insert(root->left, target);
    }
    else{
        root->right = insert(root->right, target);
    }
    return root;
}

// CORRECTED: Added inorder traversal (Left, Root, Right)
void inorder(node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// CORRECTED: Added search function
bool search(node* root, int key){
    if(!root) return false;
    if(root->data == key) return true;
    if(key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// CORRECTED: Added delete all nodes to prevent memory leak
void deleteTree(node* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    node* root = nullptr;
    int choice, value;
    
    while(true){
        cout << "\n1.Insert  2.Search  3.Display  4.Exit\nChoice: ";
        cin >> choice;
        
        if(choice == 1){
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
        }
        else if(choice == 2){
            cout << "Enter value to search: ";
            cin >> value;
            if(search(root, value)){
                cout << "Found!\n";
            }
            else{
                cout << "Not found!\n";
            }
        }
        else if(choice == 3){
            cout << "Inorder: ";
            inorder(root);
            cout << "\n";
        }
        else if(choice == 4){
            deleteTree(root);
            break;
        }
    }
    
    return 0;
}
