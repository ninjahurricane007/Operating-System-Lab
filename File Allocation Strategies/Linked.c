#include<stdio.h>

struct node
{
int data;
int nextBlock;
};
struct node memBlock[50]; int prevBlock=-1;

int main()
{
int i,j=0,size,allocated,flag=0,st; 
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
if(flag==0)
{
flag=1;
st=j;
}
memBlock[j].data=1; 
memBlock[prevBlock].nextBlock=j; 
prevBlock=j;
allocated++;
}
if(allocated==size)
{
break;
}
}
int c=st;
printf("File Allocated\n"); 
printf("%d--->%d\n",st,1); 
for(i=0;i<size-1;i++)
{
c=memBlock[c].nextBlock; 
printf("%d--->%d\n",c,1);
}
}
