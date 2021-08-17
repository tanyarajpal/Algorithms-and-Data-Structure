//binary exponentiation is an efficient way to calculate power x^y;

// # def power(x,n):
// #     res=1;
// #     while (n>0):
// #         if(int(n%2)!=0):
// #           res=res*x;
// #         x=x*x;
// #         n=int(n/2);
        
// #     return res;
    
// # x=int(input("enter base:"));
// # n=int(input("enter power:"));

// # ans=int(power(x, n))
// # print("power is :", ans);


#include<bits/stdc++.h>
typedef long long ll; 
using namespace std;

//brute force approach to calculate power  (T:O(n))
int power(ll x,ll y){
    ll res=1;
    for(ll i=1;i<=y;i++){
            res=res*x;
    }
    return res;
}

//binary exponentiation approach to find power

// recursive approach of binary exponentiation      (T:log (n))
int RbinaryExponentation(ll a,ll b){

    if(b==0) return 1;

    ll temp=RbinaryExponentation(a,b/2);
    ll res=temp*temp;
    if(b%2==1) res*=a;

    return res;
}


//iterative approach of binary exponentation    T:log(n)
int iBinaryExponentiation(ll base,ll pow){
    ll res=1;

    while(pow>0){
        if(pow%2==0){         //even condn check  // but modulo operator is heavy 
            base*=base;
            pow/=2;
        }
        else{
            res=res*base;
            pow--;
        }
    }
    return res;
}

//using bitwise opeator

int  bitwiseBinaryExponentiation(ll base,ll exp){
    ll res=1;

    while(exp>0){
        if(exp & 1){    //odd     condn check         
            
            res=res*base;
        }
        
            base=base*base;
            exp>>1;         // gives exp/2
    }
    return res;
}


int main(){
    ll a,b;
    cout<<"enter base and power :";
    cin>>a>>b;
    cout<<power(a,b)<<"\n";
    cout<< RbinaryExponentation(a,b)<<"\n";
        cout<< iBinaryExponentiation(a,b)<<"\n";

    return 0;
}