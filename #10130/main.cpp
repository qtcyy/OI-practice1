#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

vector<vector<int>> edge;

int n;
int anc[21][N],deep[N];
bool vis[N];
int cnt=1,q;

void dfs(int u){
    vis[u]=1;
    for (int& v:edge[u]){
        if (vis[v])
            continue;
        anc[0][v]=u;
        deep[v]=deep[u]+1;
        dfs(v);
    }
}

inline int getlca(int x,int y){
    if (deep[x]<deep[y])
        swap(x,y);
    for (int i=20;i>=0;i--)
        if (deep[anc[i][x]]>=deep[y])
            x=anc[i][x];
    if (x==y)
        return x;
    for (int i=20;i>=0;i--)
        if (anc[i][x]!=anc[i][y])
            x=anc[i][x],y=anc[i][y];
    return anc[0][x];
}

inline int getdis(int x,int y){
    int lca=getlca(x,y);
    return deep[x]+deep[y]-2*deep[lca];
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    edge.resize(n+1);
    for (int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if (vis[i])
            continue;
        anc[0][i]=0;
        deep[i]=1;
        dfs(i);
    }
    for (int i=1;i<=20;i++)
        for (int j=1;j<=n;j++)
            anc[i][j]=anc[i-1][anc[i-1][j]];
    cin>>q;
    while (q--){
        int x,y;cin>>x>>y;
        cout<<getdis(x,y)<<'\n';
    }

    return 0;
}