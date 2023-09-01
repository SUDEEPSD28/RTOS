#include<stdio.h>
int char_counting(const char *str)
{
int count=0;
while(*str!='\0')
{
count++;
str++;
}
return count;
}

int main(){
char input[50];
printf("enter the string\n");
scanf("%s",input);

int char_ct = char_counting(input);
printf("total number of character in strng in %d\n",char_ct);
return 0;
}

