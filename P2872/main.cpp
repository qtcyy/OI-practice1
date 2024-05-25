#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

struct Edge{
    int u,v;double w;
};

const int N = 1005;

int n,m;
int f[N];

int find(int x){
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=n;i++) f[i]=i;
    vector<Point> point;
    for (int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        point.push_back((Point){x,y});
    }
    vector<Edge> edge;
    for (int i=0;i<m;i++){
        int u,v;cin>>u>>v;u--,v--;
        // edge.push_back((Edge){u,v,dist(point[u],point[v])});
        f[find(u)]=find(v);
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            if (i==j || find(i)==find(j)) continue;
            edge.push_back((Edge){i,j,dist(point[i],point[j])});
        }

    sort(edge.begin(),edge.end(),[](const auto& p1,const auto& p2){
        return p1.w<p2.w;
    });

    double ans=0;int count=0;
    for (auto& [u,v,w]:edge){
        int x=find(u),y=find(v);
        if (x!=y){
            ans+=w;
            f[x]=y;
            if (++count==n-1) break;
        }
    }
    printf("%.2lf\n",ans);

    return 0;
}