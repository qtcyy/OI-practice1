#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n),pre(n+1);
    for (int i=0;i<n;i++){
        cin>>a[i];
        pre[i]+=pre[i-1]+a[i];
    }
    int ans=0;
    for (int i=1;i<n;i++){
        if (pre[i-1]==pre[n-1]-pre[i-1])
            ans++;
    }
    cout<<ans<<'\n';

    return 0;
}