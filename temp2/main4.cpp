#include<stdio.h>
#include<string.h>
#define MAXN 80
int main(void){
    freopen("b.in","r",stdin);
    char str[MAXN];int index;char op;char line[80];
   int m=0,q=0;
    // while((str[m]=getchar())!='\n'){
    //     m++;
    // }str[m]='\n';

    scanf("%s",str);

    for(int i=0;str[i]!='\n';i++){
        for(int j=i+1;str[j]!='\n';j++){
            if(str[i]==str[j]){
                str[j]='\0';
            }
        }
    }
    for(int i=0;str[i]!='\n';i++){
        if(str[i]!='\0'){
            str[i]=line[q];
            q++;
        }
    }line[q]='\n';
    for(int i=0;line[i]!='\n';i++){
        index=i;for(int k=i+1;line[k]!='\n';k++){
            if(line[index]>line[k]){
                index=k;
            }op=str[i];
            str[i]=str[k];
            str[k]=str[i];
        }
    }for(int i=0;line[i]!='\n';i++){
    putchar(str[i]);
    }

    return 0;
}