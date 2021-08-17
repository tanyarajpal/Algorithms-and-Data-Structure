//this is an algorithm to find minimum spanning tree


#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int parent[10005];
int ranks[10005];

struct relation{
	int u ;
	int v ;
	int w ;
};
int find(int u){
	if(parent[u]==-1){
		return u;
	}
	return parent[u] = find(parent[u]) ;
}
void Union(int u,int v){
	parent[u] = v ;
}
void UnionByPath(int u,int v){
	if(ranks[u]>ranks[v]){
		parent[v] = u ;
		ranks[u] += ranks[v] ;
	}
	else{
		parent[u] = v ;
		ranks[v] += ranks[u] ;
	}
}
bool custSort(relation r1,relation r2){
	return r1.w<r2.w ;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n+1;i++){
		parent[i] = -1;
		ranks[i] = 1;
	}

	vector<relation>vec ;
	while(m--){
		relation r;
		cin>>r.u>>r.v>>r.w ;
		vec.push_back(r) ;
	}
	int res = 0;
	sort(vec.begin(),vec.end(),custSort) ;
	for(int i=0;i<vec.size();i++){
		int a = find(vec[i].u) ;
		int b = find(vec[i].v) ;

		//not forming a cycle or belongs to different sets 
		if(a!=b){
			UnionByPath(a,b) ;
			res+=vec[i].w ;
		}
	} 
	cout<<res<<"\n" ;
}