#include <bits/stdc++.h>
using namespace std;

signed main(){
    string s;
    int count=0;
    int a=0,b=8;
    for (int i=0;i<8;i++){
        cin>>s;
        count=0;
        for (auto& c:s)
            if (c=='B')
                count++;
        if (count==8)
            a++;
        b=min(b,count);
    }
    if (a==8)
        cout<<8<<endl;
    else
        cout<<a+b<<endl;

    return 0;
}