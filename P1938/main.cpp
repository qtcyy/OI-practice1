#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int INF = 0x3f3f3f3f;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1;
int d,p,c,f,s;

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void dij(int s){
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,s});
    dis[s]=d;
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[v]<dis[u]+que[i].s){
                dis[v]=dis[u]+que[i].s;
                q.push({-dis[v],v});
            }
        }
    }
}

void spfa(int s){
    queue<int> q;
    memset(vis,false,sizeof(vis));
    // memset(dis,-1,sizeof(dis));
    q.push(s);
    dis[s]=d;
    vis[s]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[v]<dis[u]+que[i].s){
                dis[v]=dis[u]+que[i].s;
                if (!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin>>d>>p>>c>>f>>s;
    for (int i=1;i<=p;i++){
        int u,v;
        cin>>u>>v;
        add(u,v,d);
    }
    for (int i=1;i<=f;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,d-w);
    }
    spfa(s);
    int ans=-1;
    for (int i=1;i<=c;i++)
        ans=max(ans,dis[i]);
    cout<<(ans<0?-1:ans)<<'\n';
    
    return 0;
}