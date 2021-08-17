
///wrong    
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

ll prefix[10000000]={0};
void query(ll l,ll r){
    l--;
    r--;
    if(l!=0){
        cout<<prefix[r]-prefix[l-1]<<'\n';
    }
    else{
        cout<<prefix[r]<<"\n";
    }
}

void update(ll idx,ll val,ll arr[]){
    idx--;
    ll diff=abs(val-arr[idx]);
    prefix[idx]=val;
    if(val>arr[idx]){
    for(ll i=idx+1;i<n;i++){
        prefix[i]=prefix[i]+diff;
    }
    }
    else{
        for(ll i=idx+1;i<n;i++){
        prefix[i]=prefix[i]-diff;
    }
    }
    // for(ll i=0;i<n;i++)
    // cout<<prefix[i]<<" ";
    // cout<<"\n";
}
int main(){
    ll q;
    cin>>n>>q;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    prefix[0]=arr[0];
    for(ll i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    while(q--){
        ll a;
        ll b,c;
        cin>>a>>b>>c;
       // b--;
       
        //c--;
        if(a==2){
            query(b,c);
        }
        else{
            update(b,c,arr);
        }
    }
    return 0;
}