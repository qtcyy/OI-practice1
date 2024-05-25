#include <stdio.h>
#include <stdlib.h>

int a[21],b[21];

int main(){
    freopen("b.in","r",stdin);
    int n,m;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }

    

    return 0;
}