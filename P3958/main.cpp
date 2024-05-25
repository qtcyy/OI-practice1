#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point{
    ll x,y,z;
};

int t,n,h,r;
vector<int> f;

inline int find(int x){
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

inline ll dist(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z);
}

inline void merge(int x,int y){
    x=find(x);y=find(y);
    if (x!=y)
        f[x]=y;
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while (t--){
        cin>>n>>h>>r;
        f.clear();
        f.resize(n);
        for (int i=1;i<n;i++) f[i]=i;
        vector<Point> point;
        vector<int> floor_id,ceil_id;
        int x,y,z;
        for (int i=0;i<n;i++){
            cin>>x>>y>>z;
            point.push_back((Point){x,y,z});
            if (z-r<=0)
                floor_id.push_back(i);
            if (z+r>=h)
                ceil_id.push_back(i);
        }
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++){
                ll d=dist(point[i],point[j]);
                if (d<=4ll*r*r)
                    merge(i,j);
            }
        bool flag=false;
        for (auto& id1:floor_id){
            for (auto& id2:ceil_id)
                if (find(id1)==find(id2)){
                    flag=true;
                    break;
                }
            if (flag) break;
        }
        if (flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}