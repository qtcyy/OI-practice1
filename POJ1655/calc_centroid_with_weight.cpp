#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<vector<int>> edge;

int siz[N],weight[N],val[N];
int minweight,n;

void dfs(int u,int fa){
    weight[u]=0;siz[u]=val[u];
    for (int& v:edge[u]){
        if (v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        weight[u]=max(weight[u],siz[v]);
    }
    weight[u]=max(weight[u],n-siz[n]);
    minweight=min(minweight,weight[u]);
}

signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>val[i];
    edge.resize(n+1);
    for (int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    vector<int> centroid;
    for (int i=1;i<=n;i++)
        if (minweight==weight[i])
            centroid.push_back(i);
    for (int& p:centroid)
        cout<<p<<' ';
    cout<<endl;

    return 0;
}