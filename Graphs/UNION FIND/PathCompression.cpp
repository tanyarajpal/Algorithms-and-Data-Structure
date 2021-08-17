//this is an optimization technique where we optimize the find function (finding the parent of a node)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//naive find approach
//this function has worst time complexity of O(n) ;
int find(int u,int parents[]){
	if(parents[u]<0)
		return u ;
	return find(parents[u],parents) ; 
}


//iterative approach (path compression)
void pathCompressionFind(int a,int parents[]){
    vector<int>v;
   while(parents[a]>0){
       v.push_back(a) ;
       a = parents[a] ;
   }
   for(int i=0;i<v.size();i++){
       parents[v[i]] = a;
   }
   return a ;
}


//recursive approach (path compression)
void rpathCompressionFind(int a,int parents[]){
    if(parents[a]<0)
        return a ;
    // else{
    //     int x = rpathCompressionFind(parents[a],parents) ;
    //     parents[a] = x ;
    //     return x ;

    //     //or
    //     // return parents[a] = rpathCompressionFind(parents[a],parents);
    // }
    return parents[a] = rpathCompressionFind(parents[a],parents) ;
}

//naive union
void unions(int a,int b,int parents[]){
    parents[b] = a ;    //make the node a parent of node b ;
    //or
    // parents[a] = b ;

}

int main(){
	int n,m;
	cin>>n>>m;
	int parents[n+1];

    //initialize every node's parents with -1
    //none of the nodes are connected now
	for(int i=0;i<=n;i++){
		parents[i]=-1;
	}

	int u,v;
	while(m--){

        //input the relationship of 2 nodes
		cin>>u>>v;                

        int a = rpathCompressionFind(u,parents);    //find parent of u 
        int b = rpathCompressionFind(v,parents) ;   //find parent of v


		//when u and v belong to different sets ,i.e, parents are different 
        //if parent of u and v are different 
		if(a!=b)			
			unions(a,b,parents) ;	//merge both parents

	}
}