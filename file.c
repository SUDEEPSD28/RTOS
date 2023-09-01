#include<stdio.h>
#include<stdlib.h>
int main(){
FILE *fp1,*fp2;
char ch;
fp1=fopen("hi.c","r");
if(fp1==NULL)
{
printf("error");
exit(-1);
}
fp2=fopen("Hello.c","w");
if(fp2==NULL)
{
printf("error");
exit(-1);
}
ch=fgetc(fp1);
while(ch!=EOF)
{
fputc(ch,fp2);
ch=fgetc(fp1);
}
printf("%c\n",ch);
fclose(fp1);
fclose(fp2);
return 0;
}

