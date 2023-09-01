#include<stdio.h>
void scale_array(int arr[],int length,int k){
for(int i=0;i<length;i++)
{
arr[i]=arr[i]*k;
}
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
int k;
printf("enter the scale factor:");
scanf("%d",&k);
printf("original array:\t");
for(i=0;i<length;i++)
{
printf("%d\n",arr[i]);
}
scale_array(arr,length,k);
printf("array after scaling by %d:\t",k);
for(i=0;i<length;i++){
printf("%d",arr[i]);
}
return 0;}
