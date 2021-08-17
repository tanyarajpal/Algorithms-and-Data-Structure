// to find shortest path in directed weighted acyclic graph (DAG with weight)

//ALGORITHM
//1.find the topological sort using dfs
//2.


#include<bits/stdc++.h>
using namespace std;


bool dfsTopo(int node,vector<bool>&visited,vector<pair<int,int>>graph[],stack<int>&stk,vector<bool>&dfsvis){
  
    visited[node] = 1;
    dfsvis[node] = 1 ;
    for(auto &child:graph[node]){
        if(!visited[child]){
            if(dfsTopo(child,visited,graph,stk))
                return true;
        }
        if(visited[child] && dfsvis[child]) //cycle is present
            return true;
    }
    dfsvis[node] = 0;
    stk.push(node);
    return false;
}

int shortestPath(vector<pair<int,int>>graph[],int n,int start){
    vector<bool>visited(n+1,0);
    vector<bool>dfsvis(n+1,0);
    stack<int>stk;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfsTopoSort(start,visited,graph,stk,dfsvis);
        }
    }

    vector<int>dis(n+1,INT_MAX);
    dis[start] = 0;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        for(auto &i:graph[node]){
            if(dis[i.first]>dis[node]+i.second){
                dis[i.first] = dis[node]+i.second;
            }
        }
    }
    int maxi =INT_MIN;
    for(int i=1;i<=n;i++){
        if(dis[i]==INT_MAX)
            return -1;
        maxi = max(maxi,dis[i]);
    }
    return maxi;

}

int main(){

    
    return 0;
}
