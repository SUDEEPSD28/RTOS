#include<stdio.h>
void count_char(const char *str,int *counta,int *countb)
{
*counta=0;
*countb=0;
while(*str!='\0'){
if(*str=='a'){
(*counta)++;
}
else if(*str=='b'){
(*countb)++;
}
str++;
}
}

int main()
{
char input[50];
printf("enter the string:");
scanf("%s",input);
int counta,countb;
count_char(input,&counta,&countb);
printf("Total number of a is %d\n",counta);
printf("Total number of b is %d\n",countb);
}

