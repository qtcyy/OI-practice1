#include <bits/stdc++.h>
using namespace std;

int n,c,maxd;
vector<vector<int>> edge;
vector<int> dis;

void dfs(int u,int fa){
    for (int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if (v==fa) continue;
        dis[v]=dis[u]+1;
        if (dis[v]>maxd){
            maxd=dis[v];
            c=v;
        }
        dfs(v,u);
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    dis.resize(n+1);
    edge.resize(n+1);
    for (int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    dis[c]=0;maxd=0;
    dfs(c,0);
    cout<<dis[c]<<'\n';

    return 0;
}