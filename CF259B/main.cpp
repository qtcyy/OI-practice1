#include <bits/stdc++.h>
using namespace std;

const int N = 600005;

vector<vector<int>> son;

int n,q;
int fa[N];
int sum[N],ans[N],weight[N];

void dfs(int u){
    sum[u]=1;weight[u]=0;
    ans[u]=u;
    for (int v:son[u]){
        dfs(v);
        sum[u]+=sum[v];
        weight[u]=max(weight[u],sum[v]);
    }
    for (int v:son[u]){
        int p=ans[v];
        while (p!=u){
            int now=max(weight[p],sum[u]-sum[p]);
            if (now<=sum[u]>>1){
                ans[u]=p;
                break;
            }
            else
                p=fa[p];
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    cin>>n>>q;
    son.resize(n+1);
    for (int i=2;i<=n;i++){
        cin>>fa[i];
        son[fa[i]].push_back(i);
    }
    dfs(1);
    while (q--){
        int u;cin>>u;
        cout<<ans[u]<<'\n';
    }

    return 0;
}