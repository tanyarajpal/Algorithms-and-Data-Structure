#include<bits/stdc++.h>
using namespace std;
long long primeTill[10000000];
long long primePrimeTill[10000000];
long long dp[10000000]={0};
void seivePrime(long long n){

    
	dp[0]=dp[1]=1;
    for(long long i=2;i*i<=n;i++){
         if(dp[i]==0){
             for(long long j=i*i;j<=n;j+=i){
               
                    dp[j]=1;
                }
        }
    }
	primeTill[0]=0;
	primeTill[1]=0;
	primePrimeTill[0]=0;
	primePrimeTill[1]=0;
    for(long long i=2;i<=n;i++){
        if(dp[i]==0){
			primeTill[i]=1+primeTill[i-1];
			// if(dp[primeTill[i]]==0){
			// 	primePrimeTill[i]=primePrimeTill[i-1]+1;
			// }
           // cout<<i<<" ";
        }
		else{
			primeTill[i]=primeTill[i-1];
			// if(dp[primeTill[i]]==0){
			// 	primePrimeTill[i]=primePrimeTill[i-1]+1;
			//  }
		}
    }
	
    primePrimeTill[0]=0;
	primePrimeTill[1]=0;
   //primePrimeTill[2]=1;
	for(long long i=2;i<=n;i++){
			if(dp[primeTill[i]]==0){
				primePrimeTill[i]=primePrimeTill[i-1]+1;
			}
            else{
                primePrimeTill[i]=primePrimeTill[i-1];
            }
		}

    for(long long i=0;i<=10;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(long long i=0;i<=10;i++){
        cout<<primeTill[i]<<" ";
    }
    cout<<"\n";
    for(long long i=0;i<=10;i++){
        cout<<primePrimeTill[i]<<" ";
    }
    cout<<"\n";
	cout<<dp[2]<<"\n";
	cout<<primePrimeTill[2]<<"\n";
	// primePrimeTill[0]=0;
	// primePrimeTill[1]=0;
	// for(long long i=2;i<=n;i++){
	// 	long long noOfPrime=0;
	// 	if(l==0){
	// 		noOfPrime=primeTill[r];
	// 	}
	// 	else{
	// 		noOfPrime=cout<<primeTill[r]-primeTill[l-1];
	// 	}
	// 	if(dp[noOfPrime]==0){
	// 		primePrimeTill[i]=primePrimeTill[i-1]+1;
	// 	}
	// }
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	seivePrime(10000000);
	long long t;
	cin>>t;
	while(t--){
		long long l,r;
		cin>>l>>r;
		//long long count=0;
		// for(long long i=l;i<=r;i++){
		// 	if(dp[primeTill[i]]==0){
		// 		count++;
		// 	}
		// }
		// cout<<count<<"\n";
		if(l!=0){
			cout<<primePrimeTill[r]-primePrimeTill[l-1]<<"\n";
		}
		else{
			cout<<primePrimeTill[r]<<"\n";
		}
		
		// long long noOfPrime=0;
		// if(l==0){
		// 	noOfPrime=primeTill[r];
		// 	if(dp[noOfPrime]==0)
		// }
		// else{
		// 	noOfPrime=cout<<primeTill[r]-primeTill[l-1];
		// }
	}
}