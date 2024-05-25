#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int to,next;
};
node que[N];

int head[N];
bool vis[N];
int sum[N],cnt=1;

inline void add(int u,int v){
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u){
    vis[u]=1;
    sum[u]++;
    for (int i=head[u];i!=-1;i=que[i].next){
        int v=que[i].to;
        if (vis[v]) continue;
        dfs(v);
    }
}

signed main(){
    freopen("a.in","r",stdin);
    memset(head,-1,sizeof(head));
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    for (int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        dfs(i);
    }

    for (int i=1;i<=n;i++)
        if (sum[i]==n){
            cout<<i<<endl;
            return 0;
        }
    cout<<-1<<endl;

    return 0;
}