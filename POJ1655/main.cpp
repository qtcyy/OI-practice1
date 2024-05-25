#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int N = 40005;

vector<vector<int>> edge;

int sum[N],weight[N];
vector<int> centorid;
int n;

void dfs(int u,int fa){
    sum[u]=1;
    weight[u]=0;
    for (int v:edge[u]){
        if (v==fa)
            continue;
        dfs(v,u);
        sum[u]+=sum[v];
        weight[u]=max(weight[u],sum[v]);
    }
    weight[u]=max(weight[u],n-sum[u]);
    if (weight[u]<=n>>1)
        centorid.push_back(u);
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        edge.clear();
        edge.resize(n+1);
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1,0);
        cout<<centorid[0]<<' '<<weight[centorid[0]]<<'\n';
    }

    return 0;
}