#include <stdio.h>
#include <string.h>

int main(){
    char str[80];
    char c;
    scanf("%c",&c);
    getchar();
    fgets(str,sizeof(str),stdin);

    printf("%d",strlen(str));

    return 0;
}