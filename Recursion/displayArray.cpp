//this program is to display an array using recursion

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){

        if(n<0) {
            cout<<"\n";
            return;
            }

        cout<<arr[n]<<" ";
        printArray(arr,n-1);
        cout<<arr[n]<<" ";
}
int main(){


    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    printArray(arr,9);
    return 0;
}