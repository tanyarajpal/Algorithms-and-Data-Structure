//spoj problem on bfs graph

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll>prime;
ll dis[100000];
ll vis[100000];
vector<ll> adj[100000];
bool isPrime(ll a){
    ll cnt=0;
    for(ll i=2;i<=a;i++){
        if(a%i==0) cnt++;
    }
    if(cnt>1){
        return false;
    }
    return true;
}

bool isValid(ll a,ll b){
    ll cnt=0;
   while(a>0){
       if(a%10 != b%10) cnt++;
       a=a/10;
       b=b/10;
    }
    if(cnt==1) return true;
    else return false;
}

void createGraph(){
    for(ll i=1000;i<=9999;i++){
        if(isPrime(i)){
            prime.push_back(i);
        }
    }
    for(ll i=0;i<prime.size();i++){
        for(ll j=i+1;j<prime.size();j++){
            ll a=prime[i];
            ll b=prime[j];
            if(isValid(a,b)){
                adj[a].push_back(b);
                adj[b].push_back(a);
                
            }
        }
    }
   
}

void bfs(ll v){
    vis[v]=1;
    dis[v]=0;
    queue<ll>q;
    q.push(v);
    while(!q.empty()){
        ll temp=q.front();
        q.pop();
        // cout<<"fshds"<<'\n';
        for(ll i=0;i<adj[temp].size();i++){
           // cout<<"fshds"<<'\n';
            if(!vis[adj[temp][i]]){
                vis[adj[temp][i]]=1;
                q.push(adj[temp][i]);
                dis[adj[temp][i]]=dis[temp]+1;
               
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    createGraph();
    while(t--){
        ll a,b;
        cin>>a>>b;
        for(ll i=1000;i<=9999;i++){
            vis[i]=0;
            dis[i]=-1;
        }
        
        bfs(a);
        // for(ll i=1000;i<10000;i++){
        //     for(ll j=0;j<adj[i].size();j++)
        //     cout<<adj[i][j]<<" ";
        // }
        // for(ll i=a;i<=b;i++){
        //     cout<<dis[i]<<" ";
        // }
        if(dis[b]==-1) cout<<"Impossible"<<"\n";
        else cout<<dis[b]<<"\n";
        
    }
    return 0;
}
//3
// 1033 8179
// 1373 8017
// 1033 1033