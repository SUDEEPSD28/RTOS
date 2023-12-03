/*WAP which forks a new process.Let the child process initiate a counter to zero and keep incrmenting it until it reaches 999.Let it exit with a value 255.Let the parent use the waitpid() system for the child to complete.And once the child completes the parent displays a message namely "parent:child process completed:,Also let the parent output the exit value(exitststus) of the child.*/


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
//this is child process
int counter=0;
while(counter < 1000){
counter++;
}
exit(255);//exit with an status 255
}if(pid>0){
//this is parent process
int status;
waitpid(pid,&status,0);
if (WEXITSTATUS(status)){
printf("parent :child process completed\n");
printf("childs exit status :%d\n",WEXITSTATUS(status));
}
}
return 0;
}

