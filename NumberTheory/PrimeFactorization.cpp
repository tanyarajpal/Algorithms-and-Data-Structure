#include<bits/stdc++.h>
using namespace std;
 int dp[1000000]={0};
//brute force method        overall complexity ~ O(n)

void primeFactorization(int n){
    for(int i=2;i<=n;i++){      // n
        if(n%i==0){ //i will always be a prime number
            int count=0;
            while(n%i==0){      //log n             worst case will have atmost 32times 
                    n=n/i;
                    count++;
            }
            cout<<i<< " ^ " <<count<<'\n';
        }
    } 
}

//sqrt(n)  approach
void primeFactorization2(int n){
    for(int i=2;i*i<=n;i++){      // sqrt(n)
        if(n%i==0){ //i will always be a prime number
            int count=0;
            while(n%i==0){      //log n             worst case will have atmost 32times 
                    n=n/i;
                    count++;
            }
            cout<<i<< " ^ " <<count<<'\n';
        }
    }
    if(n>1){        //when given n is a prime number (then there will be no prime divisor below sqrt(n))
        cout<<n<<" ^ "<<1<<"\n";
    }
   
}



//seive method to calculate the smallest prime divisor and then prime factor is calculated using smallest prime divisor
void smallestPrimeDivisor(){
    
   //dp[1]=1;
   for(int i=0;i<=10000;i++){
       dp[i]=i;
   }
    for(int i=2;i*i<=10000;i++){
        if(dp[i]==i){
            for(int j=i*i;j<=10000;j+=i){
                if(dp[j]==j)
                    dp[j]=i;
            }
        }
    }
}
void SeivePrimeFactorizationCalc(int num){
    while(num!=1){
         cout<<dp[num]<<" ";
        num=num/dp[num];
    }
    cout<<"\n";
}


int main(){
    smallestPrimeDivisor();
    SeivePrimeFactorizationCalc(100);
    primeFactorization2(100);
    return 0;
}