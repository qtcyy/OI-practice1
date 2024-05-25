#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
vector<int> dp;

int n,d;

void dfs(int u,int fa){
    for (int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if (v==fa) continue;
        dfs(v,u);
        d=max(d,dp[u]+dp[v]+1);
        dp[u]=max(dp[u],dp[v]+1);
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    edge.resize(n+1);
    dp.resize(n+1);
    for (int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    d=0;
    dfs(1,0);
    cout<<d<<'\n';

    return 0;
}