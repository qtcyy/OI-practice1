#include <bits/stdc++.h>
using namespace std;


string myf(string s) //对s升序排列 
{
 int l=s.length();
 for(int i=0;i<l;i++)
 {
  int min=i;
  for(int j=i+1;j<l;j++)
  {
   if(atoi(&s[j])<=atoi(&s[min]))
   {
    min=j;
   }
  }
  int a=atoi(&s[i]);

  s[i]=s[min];
  s[min]=a;
  } 
}