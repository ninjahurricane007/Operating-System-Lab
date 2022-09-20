#include<stdio.h>

struct node
{
int data;
};
struct node memBlock[50];

int main()
{
int i,j=0,k=0,size,allocated,indexBlock[25]; 
for(i=0;i<50;i++)
{
memBlock[i].data=0;
}
printf("Enter the size of the file: "); 
scanf("%d",&size);
allocated=0; 
for(j=0;j<50;j++)
{
if(memBlock[j].data==0)
{
memBlock[j].data=1;
indexBlock[k]=j;
k++;
allocated++;
}
if(allocated==size)
{
break;
}
}
printf("File Allocated\n"); 
for(i=0;i<size;j++)
{
printf("%d\n",indexBlock[i]);
}
}
