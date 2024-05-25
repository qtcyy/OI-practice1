#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ch[1000];

int main(){
    freopen("a.in","r",stdin);
    scanf("%[^\n]",ch);
    int sum=0;
    int flag=0;
    for (int i=0;i<strlen(ch);i++){
        if (ch[i]!=' '){
            flag=1;
            sum++;
        }
        else if (flag){
            flag=0;
            printf("%d ",sum);
            sum=0;
        }
        // if (flag==1 && ch[i]==' ')
    }

    if (sum)
        printf("%d\n",sum);

    return 0;
}