// #include<bits/stdc++.h>
// using namespace std;
// vector<int>dp[10000000];

// int find(int n){
//     if( n == 0) return 1;
//     int ans = 0;
//     for(int i=1;i<=6;i++){
//         if(i <= n){
//           ans= (ans + find(n-i) )%(10e9+7 );
//           ans= ans % (10e9+7);
//         }
//     }
//     return dp[n]=ans;
// }

// int main(){
//     int n ;
//     cin>>n;
   
//     cout<< find(n)<<"\n";

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main() {
    int n;
    cin>>n;
   int dp[1000001]={0};
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    //32
    int mod=1000000007;

   for(int i=3;i<=n;i++){
       for(int j=i-1;j>=i-6 && j>=0 ;j--){
           dp[i]+=(dp[j])%mod;
       }
   }
   cout<<dp[n]%mod<<endl;
}