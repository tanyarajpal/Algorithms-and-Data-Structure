//this program is to find the power of a given number using logarithmic rule
//time complexity O(log(n)) that is better than O(n)
#include<iostream>
using namespace std;
int power(int x,int n){
    
    if(n==0) return 1;
    int xn= power(x,n/2);
    xn= xn*xn;

    if(n%2==1){
        xn=xn*x;
    }

    return xn;
}

int main(){
    int x,n;
    cin>>x>>n;
    int ans=power(x,n);
    cout<<ans<<"\n";
    return 0;
}
