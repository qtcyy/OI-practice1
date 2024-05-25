#include <iostream>
#include <cstring>
using namespace std;

void swap(int &a,int &b){
    cout<<&a<<' '<<&b<<endl;
    int t=a;
    a=b;
    b=t;
}

void swap1(int a,int b){
    cout<<&a<<' '<<&b<<endl;


int t=a;
    a=b;
    b=t;
}



signed main(){
    // string s="10101010101010101010101033333333";
    // int a=stoi(s);
    int *x=(int *)malloc(sizeof(int)),*y=(int *)malloc(sizeof(int));
    
    *x=1;*y=2;

    cout<<x<<' '<<y<<endl;

    int *t1=x;
    int *t2=y;
    x=t2;y=t1;


    
    cout<<x<<' '<<y<<endl;

    cout<<&*x<<' '<<*y<<endl;
}