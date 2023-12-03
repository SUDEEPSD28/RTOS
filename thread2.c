/*Write a program which creates a thread. The main thread should 
publish its pid. Let the thread publish its thread id. Next the 
thread computes the sum of first twenty five numbers and outputs the 
result to the screen. {Use pthread_join() in the main, so that it 
waits for the thread to finish its execution.} 
Modify the above code such that the upper limit of the summation is 
read from the user and is passed as a parameter to the thread.*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

void* f1(void *);
pthread_t t1;

int main()
{
    pthread_attr_t a;
    pthread_attr_init (&a);
    pthread_create(&t1,&a,f1,NULL);
    pthread_join(t1,NULL);
    return 0;
}

void* f1(void* p1)
{
    int sum=0;
    int i;
    for(i=0;i<20;i++)
    {
        sum=sum+5;
        printf("the sum of first five 20 numbers=%d\n",sum); 
 
     pthread_exit(0);
    }
}