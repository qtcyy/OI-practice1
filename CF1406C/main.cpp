#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<vector<int>> edge;

int siz[N],weight[N];
int minweight,n;
int point1,point2;

void dfs(int u,int fa){
    siz[u]=1;weight[u]=0;
    for (int& v:edge[u]){
        if (v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        weight[u]=max(weight[u],siz[v]);
    }
    weight[u]=max(weight[u],n-siz[u]);
    minweight=min(minweight,weight[u]);
}

int find(int u,int fa){
    for (int& v:edge[u]){
        if (v!=fa){
            point2=u;
            return find(v,u);
        }
    }
    return u;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    int t;cin>>t;
    while (t--){
        cin>>n;
        edge.clear();
        edge.resize(n+1);
        for (int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        minweight=n+1;
        dfs(1,0);
        vector<int> centorid;
        for (int i=1;i<=n;i++)
            if (minweight==weight[i])
                centorid.push_back(i);
        if (centorid.size()<=1){
            cout<<1<<' '<<edge[1][0]<<'\n';
            cout<<1<<' '<<edge[1][0]<<'\n';
        }
        else{
            point1=find(centorid[1],centorid[0]);
            cout<<point1<<' '<<point2<<'\n';
            cout<<centorid[0]<<' '<<point1<<'\n';
        }
    }


    return 0;
}