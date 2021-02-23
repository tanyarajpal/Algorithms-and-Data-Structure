// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void toh(int n,char source ,char mid,char destination ){
    if(n==1){
cout<<"move "<<n<<" from "<<source<<" to "<<destination<<"\n";
        return;
    }
    else{
         toh(n-1,source,destination,mid);
  cout<<"move "<<n<<" from "<<source<<" to "<<destination<<"\n";
          toh(n-1,mid,source,destination);
    }
    
}
int main() {
    
     toh(3,'a','b','c');
    return 0;

  
}