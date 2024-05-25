#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

struct Edge{
    int u,v,w;
};

int n,m;
int f[N];

inline int find(int x){
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    cin>>n>>m;
    vector<Edge> edge;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back((Edge){u,v,w});
    }
    sort(edge.begin(),edge.end(),[](const auto& p1,const auto& p2){
        return p1.w<p2.w;
    });
    int cnt=0,ans=0;
    for (int i=1;i<=n;i++)
        f[i]=i;
    for (auto& [u,v,w]:edge){
        int x=find(u),y=find(v);
        if (x!=y){
            f[x]=y;
            ans=w;
            if (++cnt==n-1) break;
        }
    }
    cout<<cnt<<' '<<ans<<'\n';

    return 0;
}