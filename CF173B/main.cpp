#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = INT_MAX;

char grid[N][N];
int n,m;
int dis[N][N][4];

int nxt[4][2]={1,0,-1,0,0,1,0,-1};

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>grid[i];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            for (int k=0;k<4;k++)
                dis[i][j][k]=INF;
    deque<tuple<int,int,int>> que;
    dis[n-1][m-1][3]=0;
    que.emplace_back(n-1,m-1,3);
    while (!que.empty()){
        auto& [x,y,dir]=que.front();
        que.pop_front();
        int d=dis[x][y][dir];
        int tx=x+nxt[dir][0],ty=y+nxt[dir][1];
        if (tx>=0 && tx<n && ty>=0 && ty<m)
            if (d<dis[tx][ty][dir]){
                dis[tx][ty][dir]=d;
                que.emplace_front(tx,ty,dir);
            }
        if (grid[x][y]=='#')
            for (int k=0;k<4;k++)
                if (k!=dir && d+1<dis[x][y][k]){
                    dis[x][y][k]=d+1;
                    que.emplace_back(x,y,k);
                }
    }
    if (dis[0][0][3]==INF)
        cout<<-1<<'\n';
    else
        cout<<dis[0][0][3]<<'\n';

    return 0;
}