//wrong spoj not taking soln

//to identify if a graph is tree  or not
// no cycles and no. of connected graphs should be one

#include<bits/stdc++.h>
using namespace std;
vector<long long>adj[100000];
// long long in[100000],out[100000];
// long long timer=0;
long long visited[100000];
void dfs(long long v){
    visited[v]=1;
    // in[v]=timer++;
    vector<long long>::iterator i;
    for(i=adj[v].begin();i<adj[v].end();i++){
        if(!visited[*i]){
            dfs(*i);
        }
    }
//    out[v]=timer++;
}
int main(){
    long long n,m;
    cin>>n>>m;
    // vector<long long>adj[n+1];
    long long u,v;
    for(long long i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back((v));
            adj[v].push_back((u));
    }
    // long long visited[n+1];
    for(long long i=0;i<=n+1;i++){
        visited[i]=0;
    }

   
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
                cnt++;
            
        }
    }

    if(cnt<=1 && (m=n-1)){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
   
    return 0;
}