#include<bits/stdc++.h>
using namespace std;

void uniqueSubsequence(unordered_set<string>&s){
    for(auto x:s){
        cout<<x<<" ";
    }
    cout<<"\n";
}
void subsequence(int i,int n,string str,string new_str,unordered_set<string>&s){
    if(i==n){
        if(new_str.length()!=0){
        s.insert(new_str);
        cout<<new_str<<" ";
        }
    }
    else{
        subsequence(i+1,n,str,new_str,s);
        subsequence(i+1,n,str,new_str+str[i],s);
    }
}
int main(){
    string str;
    cin>>str;
    unordered_set<string>s;
    subsequence(0,str.length(),str,"",s);
    cout<<"\n";
    uniqueSubsequence(s);
    return 0;
}