//euclidean theorem 
    // divident=divisor*quotient + remainder
    //a = b*quotient +  R;

    //application: used to find gcd

//extended Euclidean Theorem
    //  a * x + b * y = GCD(a,b) 

    //applications
        //used to find gcd
        //used to find modulo inverse
        //used to find LDE  i.e to solve equation ax+by=c


//problem on extended euclidean theorem
    //given 2 integers a(57) and b(81) , find solution (x,y) of the equation ax+by=GCD(a,b) 

//problem2 to find inverse

 #include<bits/stdc++.h>
 using namespace std;

int extended_euclidean(int a,int b,int &x,int &y){
    
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    int x1,y1;
    int d=extended_euclidean(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;

}


int main(){
    int x,y;
    extended_euclidean(57,81,x,y);
    cout<<x<<" "<<y<<"\n";          //displays value of x and y


    //find inverse using extended euclidean theorem
        
        //a*x+b*y=gcd(a,b)      //extended euclidean theorem
            //a*x+m*y=1             //condition for ((a^-1))  where x is the inverse of a 
            //a*x = 1 % m           //x=a^-1
    int a,m;
    cout<<"enter a and m : ";
    cin>>a>>m;
    int x1,y1;
    int g =extended_euclidean(a,m,x1,y1);
    if(g!=1){
        cout<<"no solution"<<"\n";
    }
    else{
        x1=((x1%m)+m)%m;
        cout<<x1<<"\n";
    }
    return 0;
}