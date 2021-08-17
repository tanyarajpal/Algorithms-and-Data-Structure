//program to find minimum element in a given range of static array
    //using sqareRootDecomposition

//#include<iostream>
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
//sqare root decomposition method
    ll index=0;
    ll counter=0;
    ll rootIndex=sqrt(n+1);
    ll blockIndex[n+2];
    ll minArr[rootIndex];
    ll minVal=LLONG_MAX;
    ll minArrIndex=0;
    for(ll i=0;i<n;i++){
        blockIndex[i]=index;
        minVal=min(minVal,arr[i]);
        counter++;
        if(counter==rootIndex){
            minArr[minArrIndex]=minVal;
           minVal=LLONG_MAX;
            minArrIndex++;
            counter=0;
            index++;
        }
        
    }

    

//using 2-D array (creating 2D array once takes O(n^2) and query takes(O(1)) and space is O(n^2))
    // ll dp[n][n];
    // for(ll i=0;i<n;i++){
              
    //                 dp[i][i]=i;
                
    // }
    // for(ll i=0;i<n;i++){
    //     for(ll j=i+1;j<n;j++){
    //             // if(i==j){
    //             //     dp[i][j]=i;
    //             // }
    //             // else{
    //                 if(arr[dp[i][j-1]]<arr[j]){
    //                     dp[i][j]=dp[i][j-1];
    //                 }
    //                 else{
    //                     dp[i][j]=j;
    //                 }
                   
    //           //  }
    //     }
    //}
   while(q--){
       ll l,r;
       cin>>l>>r;
        l--;
        r--;

//sqrt decomposition method query
    ll val=LLONG_MAX;
    ll leftIndex=blockIndex[l];
    ll rightIndex=blockIndex[r];
        if(leftIndex==rightIndex){
            for(ll i=l;i<=r;i++){
                val=min(val,arr[i]);
            }
            cout<<val<<"\n";
        }
        else {
            ll idx1=l;
            
            ll min1=LLONG_MAX;
            ll min2=LLONG_MAX;
            ll min3=LLONG_MAX;
          //  ll left=blockIndex[l];
           // ll right=blockIndex[r];
            while(blockIndex[idx1]==leftIndex){
                min1=min(min1,arr[idx1]);
                idx1++;
            }

            for(ll i=leftIndex+1;i<=rightIndex-1;i++){
                    min2=min(min2,minArr[i]);
                    idx1+=rootIndex;
            }
            while(idx1<=r){
                    min3=min(min3,arr[idx1]);
                    idx1++;
            }
            cout<<min(min(min1,min2),min3)<<'\n';
        }


//Brute force approach (query takes O(n))
            // ll min=arr[l];
            // for(ll i=l;i<=r;i++){
            //     if(arr[i]<min){
            //         min=arr[i];
            //     }
            // }
            // cout<<min<<"\n";
        //cout<<arr[dp[l][r]]<<"\n";
          
    }
    return 0;
}
