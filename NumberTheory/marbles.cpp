//wrong

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e7;
const int M=10e9+7;
ll fact[N+1];
ll inv[M+1];
void init(){
    fact[0]=fact[1]=1;
    for(int i=2;i<=N;i++){
        fact[i]=( (fact[i-1] % M) *  (i%M) ) % M;
    }

    inv[0]=inv[1]=1;
    for(int i=2;i<=N;i++){
        inv[i]= M- (M/i) * inv[M % i]  % M ;
        inv[i] = (inv[i] + M) % M; //To check the negative
    }
}

ll nCr(ll n,ll k){
        if(n<k){
            return 0;
        }
        
        ll res=fact[n];
        res=((res%M )* inv[fact[n-k]]%M)%M;
        res=((res%M)* inv[fact[k]%M])%M;
        return res;

}


int main(){

     init();
     ll t;
     cin>>t;
     while(t--){
    ll n,k;
    cin>>n>>k;
    cout<<nCr(n-1,k-1)<<"\n";
     }
    return 0;
}