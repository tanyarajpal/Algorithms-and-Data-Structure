#include<bits/stdc++.h>

using namespace std;

class Node{
    int curr;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void dfs(Node* root){
    if(root ==  NULL) return;
    dfs(root->left);
    dfs(root->right);
}

void bfs(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* top = q.front();
        q.pop();
        if(top ==NULL) continue;
        q.push(top->left);
        q.push(top->right);
    }
}