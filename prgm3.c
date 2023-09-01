#include<stdio.h>
 int sumofdigit(int n)   
 {
 int sum=0;
 while(n>0)
 {
 sum=sum+n%10;
 n=n/10;
 }
 return sum;
 }
 
 int main()
 {
 int n=2345;
 int sum = sumofdigit(n);
 printf("sumof digit is %d:\n",sum);
 return 0;
 }
