#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int val;
    int l,r;
};
node que[N];

int n,m;
int a[N];

void build(int p,int l,int r){
    que[p].l=l,que[p].r=r;
    if (l==r){
        que[p].val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    que[p].val=max(que[p<<1].val,que[p<<1|1].val);
}

void update(int p,int x,int v){
    if (que[p].l==que[p].r){
        que[p].val=v;
        a[que[p].l]=v;
    }
    int mid=(que[p].l+que[p].r)>>1;
    
}

int query(int p,int l,int r){

}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
}