#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;

    if(n==1)
        cout<<"1"<<"\n";
    else if(n==2||n==3)
        cout<<"NO SOLUTION"<<"\n";
    else {
        for(ll i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(ll i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}