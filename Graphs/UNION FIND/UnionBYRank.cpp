//this algorithm is used to optimize the runtime by optimizong union function

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//recursive approach (path compression)
void rpathCompressionFind(int a,int parents[]){
    if(parents[a]<0)
        return a ;
    else{
        int x = rpathCompressionFind(parents[a],parents) ;
        parents[a] = x ;
        return x ;

        //or
        // return parents[a] = rpathCompressionFind(parents[a],parents);
    }
}

//naive union function
void unions(int a,int b,int parents[]){
    parents[b] = a ;    //make the node a parent of node b ;
}

//unionByRank function 
void unionByRank(int a,int b,int parents[],int rank[]){

    if(rank[a]>rank[b]){
        parents[b] = a ;
        rank[a] += rank[b] ;
    }

    else{
        parents[a] = b ;
        rank[b] += rank[a] ;
    }
}

int main(){
	int n,m;
	cin>>n>>m;
	int parents[n+1];
    int rank[n+1];
    //initialize every node's parents with -1
    //none of the nodes are connected now
	for(int i=0;i<=n;i++){
		parents[i] = -1;
        rank[i] = 1 ;
	}

	int u,v;
	while(m--){

        //input the relationship of 2 nodes
		cin>>u>>v;                
        int a = rpathCompressionFind(u,parents);    //find parent of u 
        int b = rpathCompressionFind(v,parents) ;   //find parent of v
        
        if(a!=b) 
		unionByRank(u,v,parents,rank) ;	//merge both parents

	}
}
