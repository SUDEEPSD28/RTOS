/* (Q) Main program defines an array(Assume array size =5) and creates 
2 threads. 
One thread computes the sum of array elements.
 The second thread displays all odd numbers present in the array.
 (Pass the array as a parameter while creating the threads.) 
Aso Publish the process id and thread-id in every thread */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

void* f1(void*);
void* f2(void*);
pthread_t t1,t2;
 int main()
 {
    int arr[5]={12,6,7,8,1};
    pthread_attr_t a1;
    pthread_attr_init (&a1);
    pthread_create(&t1,&a1,f1,arr);
    pthread_create(&t2,&a1,f2,arr);
    pthread_join(t1,NULL);
    
    pthread_join(t2,NULL);
    return 0;
 }

 void* f1(void* arr)
 {
    int sum=0;
    for(int i=0;i<=4;i++)
    {
        sum=sum+((int*)arr)[i];
        
        
    }
    printf("sum is %d\n",sum);
    pthread_exit(0);
 }
 void* f2(void* arr)
 {
    for(int i=0;i<=4;i++)
{
int temp=((int*)arr)[i];
if((temp%2)!=0)
printf("the odd number is %d\n",temp);
}
pthread_exit(0);

 }