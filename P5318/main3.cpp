#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int N = 1000005;

int n,m;
bool vis[N],vis2[N];

vector<vector<int>> g;

vector<int> ans1,ans2;

struct csys{
    int x,y;
    csys(int x,int y){this->x=x;this->y=y;};
};

void dfs(int u){
    vis[u]=1;
    ans1.push_back(u);
    for (auto v:g[u]){
        if (vis[v]) continue;
        dfs(v);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis2[s]=1;
    while (!q.empty()){
        int u=q.front();q.pop();
        ans2.push_back(u);
        for (auto v:g[u]){
            if (vis2[v])
                continue;
            vis2[v]=1;
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
    memset(vis,false,sizeof(vis));
    auto start=high_resolution_clock::now();
    dfs(1);
    bfs(1);

    thread t1(dfs,1);
    thread t2(bfs,1);
    t1.join();t2.join();
    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);
    cout<<duration.count()<<'\n';

    for (auto x:ans1)
        cout<<x<<' ';
    cout<<'\n';
    for (auto x:ans2)
        cout<<x<<' ';
    cout<<'\n';

    return 0;
}