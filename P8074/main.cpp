#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

struct Point{
    ll x,y,z;
    int id;
};

struct Edge{
    int u,v;ll w;
};
vector<Edge> edge;

int f[N];
int n;
ll ans;

int find(int x){
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

void kruskal(){
    for (int i=1;i<=n;i++) f[i]=i;
    int count=0;
    sort(edge.begin(),edge.end(),[](const auto& p1,const auto& p2){
        return p1.w<p2.w;
    });
    for (auto& [u,v,w]:edge){
        int x=find(u),y=find(v);
        if (x!=y){
            f[x]=y;
            ans+=w;
            if (++count==n-1) break;
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    vector<Point> point;
    for (int i=1;i<=n;i++){
        ll x,y,z;cin>>x>>y>>z;
        point.push_back((Point){x,y,z,i});
    }
    sort(point.begin(),point.end(),[](const auto& p1,const auto& p2){
        return p1.x<p2.x;
    });
    for (int i=0;i<n-1;i++)
        edge.push_back((Edge){point[i].id,point[i+1].id,point[i+1].x-point[i].x});
    sort(point.begin(),point.end(),[](const auto& p1,const auto& p2){
        return p1.y<p2.y;
    });
    for (int i=0;i<n-1;i++)
        edge.push_back((Edge){point[i].id,point[i+1].id,point[i+1].y-point[i].y});
    sort(point.begin(),point.end(),[](const auto& p1,const auto& p2){
        return p1.z<p2.z;
    });
    for (int i=0;i<n-1;i++)
        edge.push_back((Edge){point[i].id,point[i+1].id,point[i+1].z-point[i].z});
    
    kruskal();

    cout<<ans<<'\n';

    return 0;
}