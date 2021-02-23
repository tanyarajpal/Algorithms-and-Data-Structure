//this program is to print all the permutation of a string

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cnt=0;


void permutation(string str,string new_str){

    if(str.length()==0){
        cout<<new_str<<"\n";
        cnt+=1;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        string leftstr=str.substr(0,i);
        string rightstr=str.substr(i+1);
        string finalStr=leftstr+rightstr;
        permutation(finalStr,new_str+ch); 
    }
}

int main(){
    string str;
    cin>>str;
    cnt=0;
    permutation(str,"");
      cout<<cnt<<" ";
    return 0;
}