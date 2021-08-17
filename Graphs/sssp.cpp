//single source shortest path in (TREE) using DFS
#include<bits/stdc++.h>
using namespace std;

void sssp(int v,int distance,vector<int>adj[],int visited[]){
    cout<<v<<" "<<distance<<"\n";
    visited[v]=1;
    for(int i=0;i<adj[v].size();i++){
        if(!visited[adj[v][i]]){
            sssp(adj[v][i],distance+1,adj,visited);
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+1];
    int x,y;
    for(int i=0;i<e;i++ ){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int start;
    cout<<"enter the starting node: ";
    cin>>start;
    int visited[v+1];
    for(int i=0;i<=v;i++){
        visited[i]=0;
    }
    sssp(start,0,adj,visited);
    return 0;
}