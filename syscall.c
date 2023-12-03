/*WAP which forks a new proces.BOth the parent as well as child process should display their processes ids to screen {use getpid(),and getppid() system calls}*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
pid_t pid;
pid=fork(); //creating new process

if(pid<0){
printf("Fork failed\n");
return 1;
}
if(pid == 0)
{
//this is child process
printf("child process:\n");
printf("PID:%d\n",getpid());
printf("PPID:%d\n",getppid());
}else
{
//this is parent process
printf("parent process:\n");
printf("PID:%d\n",getpid());
printf("pPID:%d\n",getppid());
}
return 0;
}
