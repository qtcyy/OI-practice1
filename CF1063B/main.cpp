#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

struct Point{
    int x,y,l,r;
};

int n,m,r,c;
int pl,pr;
char grid[N][N];
bool vis[N][N];
int nxt[4][2]={0,1/*k=0:right*/,1,0/*k=1:down*/,0,-1/*k=2:left*/,-1,0/*k=3:up*/};

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    cin>>r>>c;
    cin>>pl>>pr;
    for (int i=0;i<n;i++)
        cin>>grid[i];
    deque<Point> que;
    que.push_back((Point){r-1,c-1,pl,pr});
    vis[r-1][c-1]=1;
    while (!que.empty()){
        Point u=que.front();que.pop_front();
        for (int k=0;k<4;k++){
            if (k==0 && u.r==0 || k==2 && u.l==0) continue;
            int tx=u.x+nxt[k][0],ty=u.y+nxt[k][1];
            if (tx<0 || tx>=n || ty<0 || ty>=m || vis[tx][ty] || grid[tx][ty]=='*')
                continue;
            vis[tx][ty]=1;
            if (k==1 || k==3){
                que.push_front((Point){tx,ty,u.l,u.r});
            }
            else{
                if (k==0)
                    que.push_back((Point){tx,ty,u.l,u.r-1});
                else
                    que.push_back((Point){tx,ty,u.l-1,u.r});
            }
        }
    }
    int ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (vis[i][j]) ans++;
    
    cout<<ans<<'\n';

    return 0;
}