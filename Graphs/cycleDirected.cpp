//detect cycle in a directed graph
//approach  : DFS  or BFS (Kahn's algorithm)

#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,unordered_map<int,vector<int>>&graph,vector<bool>&visited,vector<bool>&dfsvis){
    visited[node] = 1;
    dfsvis[node] = 1;
    for(auto &child:graph[node]){
        if(!visited[child]){
            if(dfs(child,graph,visited,dfsvis))
                return true;
        }
        else if(visited[child] && dfsvis[child]){
                return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}


int main(){
    unordered_map<int,vector<int>>graph;
    int n  ;  //number of vertices in the graph
    cin>>n;
    int e;      //number of edges in the graph
    cin>>e;
    int u,v;
    for(int i=0;i<e;i++){           //input all the edges
        cin>>u>>v;
       graph[u].push_back(v);
    //    graph[v].push_back(u);        //this should not be there since it a directed graph
    }
     vector<bool>visited(n+1,0);
     vector<bool>dfsvis(n+1,0);

     //to check all connected components
    for(int i=0;i<graph.size();i++){
        if(!visited[i]){
            if(dfs(i,graph,visited,dfsvis)){
                cout<<"cycle is present"<<"\n";
                break;
                //return true;
            }
        }
    }
    // cout<<"cycle not present"<<"\n";
    //return false ;
    return 0;
}
