//this program is to find the xor of a range of array

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    ll n,q;
    cin>>n>>q;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll prefix[n];
    prefix[0]=arr[0];
    for(ll i=1;i<n;i++){
        prefix[i] = prefix[i-1] ^ arr[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<prefix[i]<<" ";
    // }
    while(q--){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a==0)
            cout<<prefix[b]<<"\n";
        else
            cout<<(prefix[b] ^ prefix[a-1])<<"\n";
    }

    return 0;
}
      