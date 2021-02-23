// //this program is to print all the prime numbers in a given range

//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void seivePrime(int n){

    int dp[n]={0};
    for(int i=2;i*i<=n;i++){
         if(dp[i]==0){
             for(int j=i*i;j<=n;j+=i){
               
                    dp[j]=1;
                }
        }
    }

    for(int i=2;i<=n;i++){
        if(dp[i]==0){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;
    cin>>n;
    seivePrime(n);
    return 0;
}