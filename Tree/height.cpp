//program to find the height of binary tree

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}
Node* insertNode(Node* root2,int data){
    if(root2==NULL) {
        root2=createNode(data);
    }

    else if(data<=root2->data){
        root2->left=insertNode(root2->left,data);
    }
    else{
        root2->right=insertNode(root2->right,data);
    }

    return root2;
}

int height(Node* root){
        if(root==NULL) return 0;
        else if(root->right==NULL && root->left==NULL) return 0;
        else{
            int h1=1+height(root->left);
            int h2=1+height(root->right);
            return h1>h2?h1:h2;
        }
}
int main(){

    Node* root=NULL;

    root=insertNode(root,10);
    root=insertNode(root,20);
    root=insertNode(root,30);
    root=insertNode(root,40);
    root=insertNode(root,5);
    root=insertNode(root,4);
    root=insertNode(root,6);
    root=insertNode(root,15);
    root=insertNode(root,53);
    int h=height(root);
    cout<<h<<"\n";
}