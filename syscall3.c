/*Create a child process which outputs your name to screen and exits with a value 255.use wait() systemcall in the parent for the child to complete execution.Also use the WEXITSTATUS macro to display the status value returned by the child.*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
int child_pid;
int status;


child_pid=fork();
if(child_pid==-1)
{
printf("Fork failed");
exit(1);
}

if(child_pid==0)
{
printf("child process:my name is VARUN\n"); //this is child process
exit(255);
}
else if(child_pid>0)
{
waitpid(child_pid,&status,0);
printf("parent process:child exited with status %d\n",WEXITSTATUS(status));
}
return 0;
}

