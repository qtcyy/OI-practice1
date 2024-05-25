#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<vector<int>> edge;

int n;
int siz[N],weight[N];
int minweight;

void dfs(int u,int fa){
    siz[u]=1;weight[u]=0;
    for (int& v:edge[u]){
        if (v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        weight[u]=max(weight[u],siz[v]);
    }
    weight[u]=max(weight[u],n-siz[u]);
    if (minweight>weight[u])
        minweight=weight[u];
}

signed main(){
    cin>>n;
    edge.resize(n+1);
    for (int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    minweight=n+1;
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