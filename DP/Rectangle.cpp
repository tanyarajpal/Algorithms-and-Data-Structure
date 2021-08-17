#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int find(int n,int m){
    // if(n == m) return 0;
    // if(n>m){
    //     return 1+find(n-m,m);
    // }
    //     return 1+find(n,m-n);
   
   if(n == 0 || m==0) return 0;
   if( n == m ) return 0;
   if( n == 1) return m-1;
   if( m == 1) return n-1;
   long int curr = 0;

   for(int i =1 ;i<min(m,n);i++){
       long int a = find(n-i,m) + find(n,m-i);
       long int b = find(n-m,i) + find(m-n,i);
       curr = min(a,b);
       ans = min
   }
}

int main(){
    fast_io;
    // int t;
    // cin>>t;
    // while(t--){
        int n,m;
        cin>>n>>m;
        int ans = find(n,m);
        cout<<ans;
    // }

}