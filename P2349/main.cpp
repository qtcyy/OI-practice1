#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n,m;
int pre[N];

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    memset(pre,0,sizeof(pre));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dis[s]=0;
    q.push({0,s});
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[v]+pre[v]>dis[u]+max(que[i].s,))
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);add(v,u,w);
    }
    dij(1);
    cout<<dis[n]+pre[n]<<'\n';

    return 0;
}