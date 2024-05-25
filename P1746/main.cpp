#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int nxt[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
};

int n;
char g[1005][1005];
bool vis[1005][1005];
int ans=INF;

void bfs(int x,int y,int x2,int y2){
    queue<pair<pair<int,int>,int>>q;
    vis[x][y]=1;
    q.push({{x,y},0});
    while (!q.empty()){
        x=q.front().first.first,y=q.front().first.second;
        int step=q.front().second;
        q.pop();
        if (x==x2 && y==y2){
            ans=min(ans,step);
            continue;
        }
        for (int k=0;k<=3;k++){
            int tx=x+nxt[k][0],ty=y+nxt[k][1];
            if (tx<1 || tx>n || ty<1 || ty>n)
                continue;
            if (!vis[tx][ty] && g[tx][ty]=='0'){
                vis[tx][ty]=1;
                q.push({{tx,ty},step+1});
            }
        }
    }

}

signed main(){
    freopen("a.in","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    bfs(x1,y1,x2,y2);   
    cout<<ans<<endl;

    return 0;
}