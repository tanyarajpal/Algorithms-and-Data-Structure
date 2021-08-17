#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int>adj[],int visited[]){
    visited[v]=1;
    // cout<<v<<" ";
    vector<int>::iterator i;
    for(i=adj[v].begin();i<adj[v].end();i++){
        if(visited[*i]==0){
            dfs(*i,adj,visited);
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int count=0;
    int visited[v+1] ;
    for(int i=0;i<=v;i++){
        visited[i]=0;
    }
    //  dfs(0,adj,visited);
    //  dfs(3,adj,visited);
    //  dfs(5,adj,visited);
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            dfs(i,adj,visited);
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}