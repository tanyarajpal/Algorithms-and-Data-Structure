//PROBLEM STATEMENT
    // Given v nodes of the tree and their connections
    //we have to find subtree size of each node of the tree
    //NOTE : the root node is given (its compulsory to define the root node because for different root nodes ,we will have different subtrees)
    
    //EXAMPLE GRAPH

    //                 0
    //             /   |   \
    //           1     2    3
    //        /  |  \
    //       4   5   6
    //      / \      /
    //     7   8    9


//SOURCE CODE

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100000];     // adjacency list to store all the nodes of the tree
int visited[100000];        //to keep track of visited nodes
int subtree_totalNodes[100000];     //stores subtree size of each nodes of the tree

//depth first search function to find the subtree size of each node of the  tree
int dfs(int v){
    visited[v]=1;
    int num=1;      //for each node initialize the number of nodes with 1
    vector<int> :: iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){      
        if(!visited[*i]){
            num+=dfs(*i);
        }
    }
    subtree_totalNodes[v]=num;  //update subtree size of node v with num
    return num;     
}


int main(){
    int v;
    cin>>v;     //read number of nodes in the tree
    int x,y;

    //take user input for the node of the tree 
    for(int i=0;i<v-1;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //read the root of the tree
    int root;
    cin >> root;  // subtrees size will be calculated on the basis of the root given by the user

    //call dfs for root node
    dfs(root);         
    
    //print the total number of subtree nodes of each node of the tree with the given root
    for(int i=0;i<v;i++){
           cout<<"node :"<< i <<"  subtree_nodes : "<<subtree_totalNodes[i]<<"\n";
    }
    return 0;
}


//USER'S INPUT AND OUTPUT

// 10 
// 0 1 
// 0 2 
// 0 3
// 1 4
// 1 5 
// 4 7 
// 4 8 
// 2 6 
// 6 9 
// 0
// node : 0 subtree_nodes : 10 
// node : 1 subtree_nodes : 5 
// node : 2 subtree_nodes : 3 
// node : 3 subtree_nodes : 1 
// node : 4 subtree_nodes : 3 
// node : 5 subtree_nodes : 1 
// node : 6 subtree_nodes : 2 
// node : 7 subtree_nodes : 1 
// node : 8 subtree_nodes : 1 
// node : 9 subtree_nodes : 1