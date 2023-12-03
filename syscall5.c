//Create a child process which executes ls command

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
pid_t child_pid;
int status;

if(child_pid==-1){
printf("Fork failed");
exit(1);
}

if(child_pid == 0)
{
execl("/bin/pwd","pwd",NULL); //this is child process//ls for listing all files date for printing the date

//if excel()fails,it will reach here
printf("excel failed");
exit(-1);
}
{
//this is parent process,wait for child to complete
wait(NULL);
printf("child process has completed.\n");
}
return 0;
}

