//hackerearth question on disjoint sets gives 

//this approach gives tle 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
//find function has worst time complexity of O(n) ;
int find(int u,int parents[]){
	if(parents[u]<0)
		return u ;
	return find(parents[u],parents) ; 
}

//enhancing of run time using path compression algorithm  to caluculate find 
//iterative
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
//recursive
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


void unions(int a,int b,int parents[]){
       
	parents[a] += parents[b] ;
    parents[b] = a ;

}

int main(){
	int n,m;
	cin>>n>>m;
	int parents[n+1];

    //initialize every nodes parents with -1
    //none of the nodes are connected now
	for(int i=0;i<=n;i++){
		parents[i]=-1;
	}

	int u,v;
	while(m--){
		cin>>u>>v;                  //input the relationship of 2 nodes
		//int a = find(u,parents) ;	//find parent of a
		//int b = find(v,parents) ;	//find parent of b

        int a = rpathCompressionFind(u,parents);
        int b = rpathCompressionFind(v,parents) ;
		//when a and b belong to different sets
		if(a!=b)			//if parent of a and b are different 
			unions(a,b,parents) ;	//merge both parents
	}
	long long int ans = 1;
	int mod = 1e9+7;
 
	for(int i=1;i<=n;i++){
		// cout<<parents[i]<<" ";
		if(parents[i]<0){
			int temp = abs(parents[i])%mod ;
			ans = (ans*temp)%mod;
		}
	}
	// cout<<"\n";
	cout<<(ans % mod)<<"\n" ;
}


