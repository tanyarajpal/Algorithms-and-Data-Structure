// to find shortest path in """ undirected weighted graph  """"
//algorithm : dijsktra 

#include<bits/stdc++.h>
using namespace std;

void bfsDijkstra(vector<pair<int,int>>graph[],int src,int n,int threshold){
    vector<int>dis(n,INT_MAX);
    priority_queue<pair<int,int>,int>pq;        // pair of wt,src
    pq.push({0,src});
    dis[src] = 0;
    while(!pq.empty()){
        int wt = pq.front().first;
        int node = pq.front().second;
        pq.pop();
        for(auto &i:graph[node]){
            if(dis[i.first]>dis[node]+i.second){
                dis[i.first] = dis[node]+i.second;
                pq.push({i.second,i.first})
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dis[i]<=threshold)
            cnt++;
    }
    return count;
}



int main(){

    vector<int>graph[n];
    int mini= INT_MAX;
    for(int i=0;i<n;i++){
        int cnt = bfsDijkstra(graph,i,n,threshold);
        if(cnt <= mini) mini = cnt;
        
    }
    return mini;
    return 0;
}