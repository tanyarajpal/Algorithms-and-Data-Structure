//wrong

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5;
const int M=10e9+7;
int fact[N+2];
int inv[N+2];
void init(){
    fact[0]=fact[1]=1;
    for(int i=2;i<=N;i++){
        fact[i]=( (fact[i-1] % M) *  (i%M) ) % M;
    }

    inv[0]=inv[1]=1;
    for(int i=2;i<=N;i++)
        inv[i]=M- (M/i) * inv[M % i]  % M ;
    
}


int nCr(int n,int k){
        if(n<k){
            return 0;
        }
        
      
        int res=fact[n];

        res=(res*inv[fact[n-k]])%M;
        res=(res*inv[fact[k]])%M;
        // res=((res%M )* (inv[fact[n-k]]%M))%M;
        // res=((res%M)* (inv[fact[k]]%M))%M;
        return res;

}


int main(){

     init();
    int n,k;
    cin>>n>>k;
    cout<<nCr(n,k)<<"\n";
    return 0;
}