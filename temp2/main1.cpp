#include<stdio.h>
#include<string.h>
int main(void){
    // freopen("a.in","r",stdin);å
    char str[1000];//&&str[i]>='0'&&str[i]<='9'
    int k=0;
    // while((str[k]=getchar())!='#'){
    //     k++;
    // }str[k]='#';
    // gets(str);
    scanf("%s",str);
    int m=0;

    int wz=0;

    for(int i=strlen(str)-1;i>=0;i--){
        if ((str[i]>='0' && str[i]<='9') || (str[i]>='A'&&str[i]<='F') || (str[i]>='a'&&str[i]<='f')){
            wz=i;
            if(str[i]>='A'&&str[i]<='Z'){
                str[i]=str[i]+'a'-'A';
            }
        }
    }

    for(int i=0;str[i]!='#';i++){
        if(str[i]>='0'&&str[i]<='9'){
            m=m*16+str[i]-'0';
        }
        else if (str[i]>='a' && str[i]<='f'){
            m=m*16+str[i]-'a'+10;
        }
    }
    

    for (int i=wz;i>=0;i--){

        if (str[i]=='-'){
            m=-m;
            break;
        }
        else if (str[i]=='+')
            break;
    }
    
    printf("%d",m);

    return 0;
}