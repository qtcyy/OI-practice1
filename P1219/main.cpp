#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int ans[N],sum;
bool a[N],b[N],c[N];

void print(){
    if (++sum<=3){
        for (int k=1;k<=n;k++)
            cout<<ans[k]<<' ';
        cout<<endl;
    }
}

void dfs(int i){
    if (i>n){
        print();
        return;
    }
    for (int j=1;j<=n;j++){
        if (!a[j] && !b[i+j] && !c[i-j+n]){
            ans[i]=j;
            a[j]=b[i+j]=c[i-j+n]=1;
            dfs(i+1);
            a[j]=b[i+j]=c[i-j+n]=0;
        }
    }
}

signed main(){
    cin>>n;
    dfs(1);
    cout<<sum<<endl;

    return 0;
}