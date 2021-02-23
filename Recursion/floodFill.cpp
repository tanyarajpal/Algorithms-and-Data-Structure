// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;
// int m,n;
// int visited[6][7];
// void floodFill(int arr[][7],int i,int j,string path){
//     if(arr[i][j]==1 || visited[i][j]==1 || i==m || j==n || i<0 || j<0){ 
//         return;
//     }
//     if(i==m-1 && j==n-1){
//         cout<<path<<"\n";
//         return;
//     }
//     visited[i][j]=1;
//     floodFill(arr,i-1,j,path + " up ");
//     floodFill(arr,i+1,j,path+" down ");
//     floodFill(arr,i,j-1,path+ " left ");
//     floodFill(arr,i,j+1,path+" right ");
//     visited[i][j]=0;
// }

// int main(){
//     //int n;
//    // cin>>m>>n;
//     m=6,n=7;
//     int arr[6][7];
//     for(int i=0;i<6;i++){
//         for(int j=0;j<7;j++){
//             visited[i][j]=0;
//         }
//     }
//     for(int i=0;i<6;i++){
//         for(int j=0;j<7;j++){
//             cin>>arr[i][j];
//         }
//     }
//     floodFill(arr,0,0," ");
//     return 0;
// }