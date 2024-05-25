#include <bits/stdc++.h>
#define int long long
#define M 1000
using namespace std;

int tot=0, head[M], nex[M], to[M], dis[M];
int d, m, n, f, s;                      //d, p, c, f, s
int vis[M], w[M], cnt[M];
priority_queue<int, vector<int>, greater<int> > q;  //大根堆

inline int read()
{
    int re=0, f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {re=re*10+(ch-'0'); ch=getchar();}
    return re*f;
}

void add_edge(int x,int y,int z)
{
    to[++tot]=y;
    dis[tot]=z;
    nex[tot]=head[x];
    head[x]=tot;
}

void Spfa()
{
    q.push(s);
    w[s]=d; vis[s]=1; cnt[s]++;
    while(!q.empty())
    {
        int u=q.top(); q.pop();
        vis[u]=0;
        if(++cnt[u]>n) {printf("-1\n"); exit(0);}  
        for(int i=head[u];i;i=nex[i])
        {
            int v=to[i];
            if(w[v]<w[u]+dis[i])
            {
                w[v]=w[u]+dis[i];      //我是用第一种求最长路的算法做的~qwq
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

signed main()
{
    freopen("a.in","r",stdin);
    d=read(); m=read(); n=read(); f=read(); s=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(), y=read();
        add_edge(x,y,d);                      //将点权转换为边权。
    }
    for(int i=1;i<=f;++i)
    {
        int x=read(), y=read(), z=read();
        add_edge(x,y,d-z);
    }
    Spfa();
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,w[i]);
    printf("%lld\n",ans);
    return 0;
}