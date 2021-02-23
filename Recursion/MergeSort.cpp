#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int h){

    int i=l;
    int j=mid+1;
    int k=0;
    int a[h-l+1]={0};
    while(i<=mid && j<=h){
            if(arr[i]<=arr[j]){
                a[k++]=arr[i++];
            }
            else{
                a[k++]=arr[j++];
            }
    }
    while(i<=mid){
        a[k++]=arr[i++];
    }
    while(j<=h){
        a[k++]=arr[j++];
    }
    k=0;
    for(int s=l;s<=h;s++){
        arr[s]=a[k];
        k++;
    }
}

void mergeSort(int arr[],int l,int h){
    if(l>=h)
        return;
    int mid=(l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);

    merge(arr,l,mid,h);
//  for(int i=0;i<6;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\n";
}


int main(){
    int arr[6]={11,12,3,53,81,1};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}