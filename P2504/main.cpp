#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Point{
    int x,y;
};

struct edge{
    int u,v;double w;
};

int n,m;
int f[N];
int val[N];

inline int find(int x){
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

inline int dist(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>val[i];
    cin>>m;
    for (int i=1;i<=m;i++) f[i]=i;

    vector<Point> point(m);
    
    for (int i=0;i<m;i++)
        cin>>point[i].x>>point[i].y;
    vector<edge> e;
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++){
            if (i==j) continue;
            int dis=dist(point[i],point[j]);
            e.push_back((edge){i,j,sqrt(dis)});
        }
    
    sort(e.begin(),e.end(),[](const auto& p1,const auto& p2){
        return p1.w<p2.w;
    });

    double sum=0;int count=0;
    for (auto& p:e){
        int x=find(p.u),y=find(p.v);
        if (x!=y){
            f[x]=y;
            sum=p.w;
            if (++count==m-1)
                break;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        if (val[i]>=sum)
            ans++;
    cout<<ans<<'\n';

    return 0;
}