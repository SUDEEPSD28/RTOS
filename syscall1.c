/*create a child process form a program. Let child process first sleep for 8 seconds and then output a message "i am child process".Parents outputs a message "i am parent"and then waits for child to complete.*/ 

#include<sys/types.h>
#include<sys/wait.h>
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
sleep(8);//sleep for 8 seconds
printf("I am child process\n");
//exit(10);
}
if(pid>0) {
int status;//wait for child process to complete
wait(NULL);
printf("i am parent process\n"); //this is parent process

//int status;//wait for child process to complete
//wait(&status);
printf("parent process:\n");
printf("PID:%d\n",getpid());
printf("pPID:%d\n",getppid());
}
return 0;
}
