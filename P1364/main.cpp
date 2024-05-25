#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int inf=0x3f3f3f3f;

vector<vector<int>> edge;

int siz[N],f[N],deep[N];
int weight[N];
int n,ans=inf;

void dfs(int u,int fa){
    siz[u]=weight[u];
    for (int& v:edge[u]){
        if (v==fa) continue;
        deep[v]=deep[u]+1;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    f[1]+=weight[u]*deep[u];
}

void dp_dfs(int u,int fa){
    for (int& v:edge[u]){
        if (v==fa) continue;
        f[v]=f[u]+siz[1]-2*siz[v];
        dp_dfs(v,u);
    }
    ans=min(ans,f[u]);
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    cin>>n;
    edge.resize(n+1);
    for (int i=1;i<=n;i++){
        int u,v;
        cin>>weight[i]>>u>>v;
        if (u)
            {edge[u].push_back(i);edge[i].push_back(u);}
        if (v)
            {edge[v].push_back(i);edge[i].push_back(v);}
    }
    dfs(1,0);
    dp_dfs(1,0);
    cout<<ans<<'\n';

    return 0;
}