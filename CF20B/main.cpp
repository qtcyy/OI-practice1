#include <bits/stdc++.h>
using namespace std;

signed main(){
    int a,b,c;
    cin>>a>>b>>c;
    int delta=b*b-4*a*c;
    if (delta>0){
        cout<<2<<endl;
        double x1=(-b*1.0+sqrt(delta))/(2.0*a);
        double x2=(-b*1.0-sqrt(delta))/(2.0*a);
        cout<<min(x1,x2)<<endl<<max(x1,x2)<<endl;
    }
    else if (delta==0){
        cout<<1<<endl;
        double x=-b*1.0/(2.0*a);
        cout<<x<<endl;
    }
    else
        cout<<0<<endl;
    
    return 0;
}