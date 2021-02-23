/*
        we can traverse a tree in two ways
        1.BREADTH FIRST
                level order traversal

        2.DEPTH FIRST
                preorder            root,left,right
                inorder             left,root,right
                postorder           left,right,root

*/
#include<iostream>
#include<queue>
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

void preorder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;

   
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);
}
void levelOrder(Node* root){
    if(root==NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        cout<<temp->data<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        q.pop();
    }
    cout<<"\n";
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
    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
      levelOrder(root);
    
}