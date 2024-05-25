#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

const int N = 505;

int nxtg[4][2]={0,0,-1,0,-1,-1,0,-1};//格子
int nxtp[4][2]={1,1,-1,1,-1,-1,1,-1};//点
char stat[5]="\\/\\/";

int n,m;
char grid[N][N];
int dis[N][N];

void bfs(){
    memset(dis,0x3f,sizeof(dis));
    deque<pair<int,int>> que;
    que.emplace_back(0,0);
    dis[0][0]=0;
    while (!que.empty()){
        auto& [x,y]=que.front();
        que.pop_front();
        for (int k=0;k<4;k++){
            int txg=x+nxtg[k][0],tyg=y+nxtg[k][1];
            int txp=x+nxtp[k][0],typ=y+nxtp[k][1];
            if (txp<0 || txp>n || typ<0 || typ>m)
                continue;
            if (stat[k]!=grid[txg][tyg]){
                int dist=dis[x][y]+1;
                if (dist<dis[txp][typ]){
                    dis[txp][typ]=dist;
                    que.emplace_back(txp,typ);
                }
            }
            else{
                int dist=dis[x][y];
                if (dist<dis[txp][typ]){
                    dis[txp][typ]=dist;
                    que.emplace_front(txp,typ);
                }
            }
        }
    }
    cout<<dis[n][m]<<'\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>grid[i];
    if ((n+m)&1)
        cout<<"NO SOLUTION\n";
    else
        bfs();
    
    return 0;
}