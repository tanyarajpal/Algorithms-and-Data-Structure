// Program to find maximum element in Binary Search Tree
#include <iostream>
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
int IterativeMax(Node* root2){
    if(root2==NULL) return 0;
    while(root2->right!=NULL){
        root2=root2->right;
    }
    return root2->data;
}
int maxElement(Node* root2){
    if(root2==NULL) return 0;
    if(root2->right==NULL) return root2->data;
    else {
       return maxElement(root2->right);
    }
}
Node* insertNode(Node *root2,int val){
    if(root2==NULL){
        root2=createNode(val);
    }
    
    else if(val<=root2->data){
        root2->left=insertNode(root2->left,val);
    }
    else{
        root2->right=insertNode(root2->right,val);
    }
    return root2;
}
int main() {
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
    cout<<maxElement(root)<<"\n";
    cout<<IterativeMax(root)<<"\n";
    return 0;
}