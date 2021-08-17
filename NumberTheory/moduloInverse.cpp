//modulo multiplicative inverse 
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll n = 10e5;
ll dp[n];
 


//modulo inverse using binary exponentitation (fermat little theorem)
ll binaryExpo(ll base,ll power){
    
    ll res=1;
    while(power>0){
        if(power&1) res=((res%mod) *(base%mod))%mod;
        base=(base*base)%mod;
        power=power>>1; 
    }
    return res%mod;
}


//using extended euclidean theorem
ll extended_euclidean(ll a,ll b,ll &x,ll &y){
    
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    ll x1,y1;
    ll d=extended_euclidean(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;

}

//using dp approach

void calc(){
    dp[0] = dp[1] = 1;
    for (ll i = 2; i < n; i++) {
        dp[i] = (dp[mod % i] * (-(mod / i))) % mod;
        dp[i] = (dp[i] + mod) % mod; //To check the negative
    }
}


int main(){
    ll a;
    
    
        
    cin>>a;
    cout<<"modulo inverse : "<<a<<"^-1 %"<<mod<<"\n";
      
        //using fermat little theroem
        //a^m-1 = 1 %  mod     
        // a^m-2 = a^-1 % mod
        //find a ^ m-2 
    cout<<binaryExpo(a,mod-2)<<"\n";  




        //using extended euclidean theorem      
         ll x,y;
        ll g =extended_euclidean(a,mod,x,y);
         if(g!=1){
          cout<<"no solution"<<"\n";
      }
      else{
            x=((x%mod)+mod)%mod;
             cout<<x<<"\n";
          }


    //using dp aprroach
        calc();
        cout<<dp[a]<<"\n";
    return 0;
}