#include<stdio.h>

int sum1(int n)
{
int i;
int sum=0;
for(i=0;i<=n;i++)
{
sum=sum+i;
}
return sum;
}

int main()
{
int a=6;

int sum= sum1(a);
printf("sum is %d:\n",sum);
return 0;
}
