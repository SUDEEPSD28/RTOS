#include<stdio.h>
int smallest_number(int arr[],int length){
int i;
if(length==0)
{
return -1;
}
int smallest=arr[0];
for(i=0;i<length;i++)
{
if(arr[i]<smallest){
smallest=arr[i];
}
}
return smallest;
}


int main()
{
int length,i;
printf("enter the array length\n");
scanf("%d",&length);
if(length<=0)
{
printf("invalid\n");
}
int arr[length];
for(i=0;i<length;i++)
{
printf("enter elements %d:",i+1);
scanf("%d",&arr[i]);
}
int smallest=smallest_number(arr,length);
if(smallest!=-1)
{
printf("smallest number is %d\n",smallest);
}
else
{
printf("array is empty\n");
}
return 0;
}
