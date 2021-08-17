//find the longest path of the tree
    //this means we have to find the diameter of the tree

#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
vector<long long>adj[100000];
long long visited[100000];
long long maxDist=LLONG_MIN;
long long node=-1;
void dfs(int v,int distance){
    
    visited[v]=1;
    if(distance>maxDist) {
        maxDist=distance;
        node=v;
        }
    vector<long long>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            dfs(*i,distance+1);
        }
    }
}
int main(){
    ll n;
    cin>>n;
    ll x,y;
    for(ll i=0;i<=n;i++){
        visited[i]=0;
    }
    for(ll i=0;i<n-1;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);

    for(ll i=0;i<=n;i++){
        visited[i]=0;
    }
    maxDist=LLONG_MIN;
    dfs(node,0);
    cout<<maxDist<<'\n';
    return 0;
}