#include<stdio.h>
#include<string.h>
int main()
{
 char a[85];
 gets(a);
    int i=0;
    int len=0;
 len=strlen(a);
    int j=0;
    char t;
    for(i=0;i<len-1;i++)
    {
     for(j=0;j<len-i-1;j++)
     {
      if(a[j]>a[j+1])
      {
       t=a[j];
       a[j]=a[j+1];
       a[j+1]=t;
   }
  }
 }
 for(i=0;i<len;i++)
 {
  if(a[i]!=a[i+1])
  printf("%c",a[i]);
 }//此段为重点
}