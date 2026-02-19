#include<stdio.h>
#include <vector>
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    public:
    node(int data){
        this->data= data;
        right=left = nullptr;

    }

};
int index=0;

node* buildTree(std::vector<int> pre){
   index++;
   if(pre[index]==-1){
       return nullptr;
   }

   node* root = new node(pre[index]);
   root->left = buildTree(pre);
   root->right = buildTree(pre);



}

int main(){

}