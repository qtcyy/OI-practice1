#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ch[1000];

int main(){
    freopen("a.in","r",stdin);
    // ch=(char *)malloc(sizeof(char)*1000);

    scanf("%[^\n]",ch);
    // printf("%s",ch);
    int sum=0;
    for (int i=1;i<strlen(ch);i++){
        if (ch[i-1]==' ' && ch[i]!=' '){
            sum++;
        }
    }
    if (ch[0]!=' ')
        printf("%d\n",sum+1);
    else
        printf("%d\n",sum);

    return 0;
}