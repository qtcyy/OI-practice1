#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 10005;
const int M = 1e7+5;

int t,m;
int w[N],v[N];
ll f[M];

signed main(){
    cin>>m>>t;
    for (int i=1;i<=t;i++)
        cin>>w[i]>>v[i];
    for (int i=1;i<=t;i++)
        for (int j=w[i];j<=m;j++)
            f[j]=max(f[j],f[j-w[i]]+v[i]);
    cout<<f[m]<<endl;

    return 0;
}