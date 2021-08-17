//wrong

// #include<bits/stdc++.h>
// typedef long long ll;
// using namespace std;
// const int MOD = 1e9 + 7;

//  ll matrix[100][100];
//  ll I[100][100];

// void mul(int flag,ll m){
//     ll res[m][m];
//     for(ll i=0;i<m;i++){
//         for(ll j=0;j<m;j++){
           
//             res[i][j]=0;
//         }
//     }
//     if (flag==0){
//         for(ll i=0;i<m;i++){
//         for(ll j=0;j<m;j++){
//             for(ll k=0;k<m;k++){
//                 res[i][j]=(res[i][j]%MOD
//                                 +
//                             (matrix[i][k]%MOD  *   matrix[k][j]%MOD)  % MOD) % MOD;
//             }
//         }
//     }
//     }
//     else if (flag==1){
     
//     // ll res[m+1][m+1];
//     // for(ll i=0;i<m;i++){
//     //     for(ll j=0;j<m;j++){
//     //         res[i][j]=0;
//     //     }
//     // }
    
//     for(ll i=0;i<m;i++){
//         for(ll j=0;j<m;j++){
//             for(ll k=0;k<m;k++){
//                 res[i][j]=res[i][j]+(matrix[i][k]*I[k][j]);
//             }
//         }
//     }
//     }
//     for(ll i=0;i<m;i++){
//         for(ll j=0;j<m;j++){
//                 matrix[i][j]=res[i][j];
//         }
//     }
// }
// void matrixExponentiation(ll n,ll m){

//         //ll I[m][m];
//         for(ll i=0;i<m;i++){
//             for(ll j=0;j<m;j++){
//                 if(i==j)
//                 I[i][j]=1;
//                 else
//                 I[i][j]=0;
//             }
//         }
//     //     // ll res[m][m]=I;
//     //      ll res[m+1][m+1];
//     // for(ll i=0;i<m;i++){
//     //     for(ll j=0;j<m;j++){
//     //         res[i][j]=0;
//     //     }
//     // }
//         while(n--){
//             mul(0,m);
//         }
//         // while(n>0){
//         //     if(n%2){
//         //        // res=res*matrix
//         //         mul(1,m);
//         //         n--;
//         //     }
//         //     else{
//         //         mul(0,m);
//         //         n/=2;
//         //        // n>>1;
//         //     }
//         // }
//  // ll res[m+1][m+1];
//     // for(ll i=0;i<m;i++){
//     //     for(ll j=0;j<m;j++){
//     //             matrix[i][j]=res[i][j];
//     //     }
//     // }
//     //     for(ll i=0;i<m;i++){
//     //     for(ll j=0;j<m;j++){
//     //             matrix[i][j]=I[i][j];
//     //     }
//     // }
// }
// void printMatrix(ll m){
//     for(ll i=0;i<m;i++){
//         for(ll j=0;j<m;j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll m;
//         ll n;

//         cin>>m>>n;
//         // ll matrix[m][m];
//         for(ll i=0;i<m;i++){
//             for(ll j=0;j<m;j++){
//                 cin>>matrix[i][j];
//             }
//         }
      
//         matrixExponentiation(n,m);
//         printMatrix(m);
//     }
//     return 0;
// }