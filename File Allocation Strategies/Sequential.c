#include<stdio.h>

struct node
{
int data;
};
struct node memBlock[50];

int main()
{
int i,start,size; 
for(i=0;i<50;i++)
{
memBlock[i].data=0;
}
printf("Enter the starting block: "); 
scanf("%d",&start);
printf("Enter the size of the file: "); 
scanf("%d",&size);
int flag=0; 
for(i=start;i<start+size;i++)
{
if (memBlock[i].data==1)
flag=1; 
break;
}
if(flag==0)
{
for(i=start;i<start+size;i++)
{
memBlock[i].data=1;
printf("%d--->%d\n",i,memBlock[i].data);
}
printf("File Allocated");
}
if(flag==1)
{
printf("File Not Allocated");
}
}


