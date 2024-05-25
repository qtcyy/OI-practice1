#include <stdio.h>
#include <string.h>

const int N = 80;

char ans[N];

int main(){
    // freopen("b.in","r",stdin);
    char str[N];

    // int m=0;
    // while((str[m]=getchar()) && str[m]!='\n'){
    //     m++;
    // }str[m]='\n';
    
    // gets(str);
    scanf("%[^\n]",str);

    int n=strlen(str);
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (str[i]>str[j]){
                char t=str[i];str[i]=str[j];str[j]=t;
            }
    
    int t=0;
    for (int i=1;i<n;i++)
        if (str[i-1]!=str[i])
            ans[t++]=str[i-1];
    
    ans[t++]=str[n-1];
    printf("%s\n",ans);

    return 0;
}