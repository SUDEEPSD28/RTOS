#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

void* f1(void*);
void* f2(void*);
void* f3(void*);
pthread_t t1,t2,t3;

int main()
{
    pthread_attr_t a1;
    pthread_attr_init (&a1);
    pthread_create(&t1,&a1,f1,NULL);
    pthread_create(&t2,&a1,f2,NULL);
    pthread_create(&t2,&a1,f3,NULL);

    pthread_join(t1,NULL);
    
    pthread_join(t2,NULL);
    
    pthread_join(t3,NULL);
    return 0;

}

void* f1(void* p1)
{
    sleep(2);
    printf("thread1:Helloworld\n");
    //printf("thread1 with id %lu\n",pthread_self);
    pthread_exit(0);
}

void* f2(void* p2)
{
    sleep(2);
    printf("thread2:Hello sudeep\n");
    //printf("thread2 with id %lu\n",pthread_self);
    pthread_exit(0);
}

void* f3(void* p3)
{
    sleep(2);
    printf("thread3:Hello msis\n");
    //printf("thread3 with id %lu\n",pthread_self);
    pthread_exit(0);
}

