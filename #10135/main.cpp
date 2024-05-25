#include <bits/stdc++.h>
using namespace std;

const int N = 80005;

vector<vector<int>> edge(N);

int anc[21][N],deep[N];
bool vis[N];
int n,q;

void dfs(int u){
    vis[u]=1;
    for (int& v:edge[u]){
        if (vis[v]) continue;
        deep[v]=deep[u]+1;
        anc[0][v]=u;
        dfs(v);
    }
}

inline int getlca(int x,int y){
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=20;i>=0;i--)
        if (deep[anc[i][x]]>=deep[y])
            x=anc[i][x];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
        if (anc[i][x]!=anc[i][y])
            x=anc[i][x],y=anc[i][y];
    return anc[0][x];
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    vector<int> root;
    for (int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        if (v==-1){
            root.push_back(u);
            continue;
        }
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    for (int& u:root){
        if (vis[u]) continue;
        deep[u]=0;
        anc[0][u]=u;
        dfs(u);
    }

    for (int i=1;i<=20;i++)
        for (int j=1;j<=N;j++)
            anc[i][j]=anc[i-1][anc[i-1][j]];
    cin>>q;
    while (q--){
        int u,v;cin>>u>>v;
        int lca=getlca(u,v);
        // cout<<lca<<'\n';
        if (u==lca)
            cout<<"1\n";
        else if (v==lca)
            cout<<"2\n";
        else
            cout<<"0\n";
            
    }

    return 0;
}