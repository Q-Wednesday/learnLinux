#include <cstdio>
#include"stdio.h"
#include"math.h"
int main()
{
 int a,b,c,m[9]={1,2,3,4,5,6,7,8,9},sigh[9]={0,0,0,0,0,0,0,0,0};
 float d;
 int flag=0;//flag表示这一轮有没有找到一个数，如果找到了，就不应该把a,b,c的sign置为0
 for(a=0;a<=8;a++)
   {if(sigh[a]==1) continue;
 sigh[a]=1;
   for(b=0;b<=8;b++)
  {if(sigh[b]==1) continue;
   sigh[b]=1;
    for(c=0;c<=8;c++)
  {if(sigh[c]==1) continue;
    sigh[c]=1;
  if(m[a]!=m[b]&&m[b]!=m[c]&&m[a]!=m[c])
          {     d=m[a]*100+m[b]*10+m[c];
    if ((int)sqrt(d) * (int)sqrt(d) == d) {
      flag=1;
      printf("  %.0f   ", d);
      }
    else sigh[c]=0;
       }
    }
  if(flag!=1)
   sigh[b]=0;
   }
   if(flag!=1)
     sigh[a] = 0;
   else {
     flag=0;//重置flag开始下一轮
   }
 }
 return 0;
}