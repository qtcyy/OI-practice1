#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
using namespace std;

const int N = 100005;

int n,m;
bool vis[N];
vector<set<int>> g;

void dfs(int u){
    cout<<u<<' ';
    vis[u]=1;
    for (auto v:g[u]){
        if (vis[v]) continue;
        dfs(v);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u=q.front();q.pop();
        if (vis[u])
            continue;
        cout<<u<<' ';
        vis[u]=1;
        for (auto v:g[u])
            if (!vis[v])
                q.push(v);
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    g.resize(n+1);
    for (int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        g[u].insert(v);g[v].insert(u);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    memset(vis,false,sizeof(vis));
    cout<<'\n';
    bfs(1);
    cout<<'\n';

    return 0;
}