#include<bits/stdc++.h>
using namespace std;

void prefixSumArr(int arr[],int n,int prefixArr[]){
    prefixArr[0]=arr[0];
    for(int i=1;i<n;i++){
        prefixArr[i]=prefixArr[i-1]+arr[i];
    }
    cout<<"prefix sum array"<<"\n";
    for(int i=0;i<n;i++){
        cout<<prefixArr[i]<<" ";
    }
    cout<<"\n";
}

void rangeSum(int l,int r,int prefixArr[]){
    cout<<"sum of elements between the range "<<l<<" and "<<r<<": ";
    if(l!=0)
        cout<< (prefixArr[r]-prefixArr[l-1])<<"\n";
    else
        cout<< (prefixArr[r])<<"\n";
    
}
int main(){
    //int arr[5]={1,2,3,4,5};
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    int arr[n],prefixArr[n];
    memset(prefixArr,0,sizeof(prefixArr));
    cout<<"enter "<<n<<" array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    prefixSumArr(arr,5,prefixArr);
    rangeSum(1,4,prefixArr);
    return 0;
}