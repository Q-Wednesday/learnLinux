#include <stdio.h>

int main()
{
    int m,k,j,a,b,c,max_a,max_b,max_c;
    double n,d,i;
    printf("Give your money,the program will help you calculate the best way to save: ");
    scanf("%lf",&n);
        for(a=0;a<=10;a++)
        {
            for(b=0;b<=(30-(a*3))/2;b++)
            {       i=n;
                for(m=1;m<=a;m++)
                {
                       i=i*(1.035)*(1.035)*(1.035);
                }
                for(k=1;k<=b;k++)
                {
                      i=i*(1.0285)*(1.0285);
                }
                for(j=1;j<=30-(3*a)-(2*b);j++)
                {
                      i=i*(1.0225);
                }
                printf("%d %d %lf %lf\n",a,b,i,d);
                if(i>=d)
                {
                      d=i;
                      max_a = a;
                      max_b = b;
                      max_c=30-(3*a)-(2*b);
                }

            }
        }
        printf("one year:%d two years:%d three years:%d  Your final money:%lf",max_c,max_b,max_a,d);
    return 0;
}
