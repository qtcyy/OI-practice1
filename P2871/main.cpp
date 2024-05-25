#include <bits/stdc++.h>
using namespace std;

int f[200005];
int w[200005],v[200005];

signed main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for (int i=1;i<=n;i++)
        for (int j=m;j>=w[i];j--)
            f[j]=max(f[j],f[j-w[i]]+v[i]);
    cout<<f[m]<<endl;

    return 0;
}