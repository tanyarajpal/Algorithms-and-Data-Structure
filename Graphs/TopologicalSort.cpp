//in order to perform a topological sort , the graph should be :
// directed and acyclic 
//approaches : dfs  and bfs(Kahn's algo)

///if cycle is present , then topological sorting is not possible
#include<bits/stdc++.h>
using namespace std;

bool dfsTopo(int node,vector<bool>&visited,unordered_map<int,vector<int>>&graph,stack<int>&stk,vector<bool>&dfsvis){
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

void bfs(unordered_map<int,vector<int>>&graph,vector<int>&res){
    queue<int>q;
    vector<int>indegree(graph.size(),0);
    for(auto &i:graph){
        indegree[i.first]++;
    }
    for(auto &i:indegree){
        if(i==0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        res.push(node);
        q.pop();
        cnt++;
        for(auto &child:graph[node]){
            indegree[child]--;
            if(indegree[child] == 0){
                q.push(child);
            }
        }
    }

    //condition check for cycle
    if(cnt == graph.size()) 
       cout<<"cycle not present";
    else
        cout<<"cycle present";

    //topological sorted vector
    for(auto &i:res)
        cout<<i<<" ";
    
}

int main(){
    unordered_map<int,vector<int>>graph;
    int n ;
    cin>>n;
    //create the directes graph
    for(int i=0;i<e;i++){
        cin>>u;
        cin>>v;
        graph[u].push_back(v);
    }
    //to check for all connected components
    stack<>stk;
    vector<int>res;
    vector<bool>visited(n+1,0);
     vector<bool>dfsvis(n+1,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfsTopo(i,visited,graph,stk,dfsvis))     //if cycle is present
            {
                return res;                 //return empty ,topogical sorting not possible
            }
        }
    }
    //no cycle present , so we have topological sorted stack 
    for(!stk.empty){            
        res.push_back(stk.top());
        stl.pop();
    }
    return res;
}