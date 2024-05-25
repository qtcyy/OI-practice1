#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> mp;

signed main(){
    freopen("b.in","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (mp.find(x)==mp.end())
            mp[x]=1;
        else
            mp[x]++;
    }
    cin>>m;
    for (int i=1;i<=m;i++){
        int x;cin>>x;
        if (mp.find(x)==mp.end())
            mp[x]=1;
        else
            mp[x]++;
    }

    for (auto p:mp){
        if (p.second==1)
            cout<<p.first<<' ';
    }
    return 0;
}