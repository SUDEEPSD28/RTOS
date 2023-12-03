#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{
    char *sm;
    char *sm1;
    const int len=4096;
    int seg_id;
    seg_id= shmget(IPC_PRIVATE,len,S_IRUSR|S_IWUSR);
    sm=(char*)shmat(seg_id,NULL,0);
    sm1=(char*)shmat(seg_id,NULL,0);
    sprintf(sm,"sudeep");
    printf("%s\n",sm);

    sprintf(sm1,"hello sd");
    printf("%s",sm1);
    printf("\n");

    printf("%s\n",sm);

    shmdt(sm);
    shmdt(sm1);

    shmctl(seg_id,IPC_RMID,NULL);
    return 0;

}