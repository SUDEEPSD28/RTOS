/*Let a parent process create a segment of adequate length and
write 0 to 9 as well as 'a' to 'z' to it.Next, let the parent fork a
child.Let the child increment all the integers by a value 100. Also
let it convert all the characters to upper case. Once the child
completes, let the parent access the shared area and display their
contents to the screen.*/


#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int seg_id;
char *sm;
char *sm1;
char ch='a';
const int len=100;
int low=32;
int id1,id2,data=0;

id1=fork();

if(id1>0)
{
printf("iam the first parent\n");
seg_id=shmget( IPC_PRIVATE, len, S_IRUSR | S_IWUSR ); //allocate
sm=(char *) shmat(seg_id, NULL, 0); // attach
sm1=(char *) shmat(seg_id, NULL, 0); // attach

for(int i=0;i<=10;i++)
{
*(sm+i)=data; 
data++;
}

for(int i=10;i<36;i++)
{
*(sm+i)=ch; 
ch++;
}

for(int i=0;i<10;i++)
{
printf("%d\t",*(sm+i));
}
printf("\n");

/for(int i=10;i<36;i++)
{
printf("%c\t",*(sm+i));// accessing same value and adding 32 to convert upper case to lower case
}
printf("\n");


id2=fork();

if(id2>0)
{
printf("iam the second parent\n");
for(int i=0;i<10;i++)
{
*(sm+i)=*(sm+i)+100; 
}

for(int i=10;i<36;i++)
{
*(sm+i)=*(sm+i)-32; 
}
}
else if(id2==0)
{
printf("iam the second child\n");

for(int i=0;i<10;i++)
{
printf("%d\t",*(sm+i));
}
printf("\n");

for(int i=10;i<36;i++)
{
printf("%c\t",*(sm+i));// accessing same value and adding 32 to convert upper case to lower case
}
printf("\n");
}
}


shmctl(seg_id,IPC_RMID,NULL); //deallocating the segment from the memory area
return 0;
}