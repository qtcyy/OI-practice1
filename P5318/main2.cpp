#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int N = 1000005;

int n,m;
bool vis[N];

vector<vector<int>> g;

vector<int> ans1,ans2;

struct csys{
    int x,y;
    csys(int x,int y){this->x=x;this->y=y;};
};

void dfs(int u){
    vis[u]=1;
    cout<<u<<' ';
    for (auto v:g[u]){
        if (vis[v]) continue;
        dfs(v);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while (!q.empty()){
        int u=q.front();q.pop();
        cout<<u<<' ';
        for (auto v:g[u]){
            if (vis[v])
                continue;
            vis[v]=1;
            q.push(v);
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    vector<csys> v;
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(csys(x,y));
    }
    sort(v.begin(),v.end(),[](csys p1,csys p2){
        if (p1.x<p2.x)
            return true;
        else if (p1.x==p2.x)
            return p1.y<p2.y;
        return false;
    });
    g.resize(n+1);
    for (auto p:v)
        g[p.x].push_back(p.y);
    auto start=high_resolution_clock::now();
    memset(vis,false,sizeof(vis));
    dfs(1);
    cout<<'\n';
    memset(vis,false,sizeof(vis));
    bfs(1);
    auto stop=high_resolution_clock::now();
    cout<<'\n';
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<duration.count()<<'\n';

    return 0;
}