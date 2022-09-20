#include<stdio.h>
int main()
{
int m,n,b[25],p[25],i,j,mem[25],t[25];
printf("Enter the no. of memory blocks: ");
scanf("%d",&m);
printf("Enter the no. of process: ");
scanf("%d",&n);
printf("Enter the size of memory blocks: ");
for(i=0;i<m;i++)
{
scanf("%d",&b[i]);
}
printf("Enter the size of process: ");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
for(i=0;i<25;i++)
{
mem[i]=0;
t[i]=-1;
}

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(mem[j]==0 && p[i]<b[j])
{
mem[j]=1;
t[j]=i;
break;
}
}
}
printf("Memory Block\tBlock Size\tProcess No\tProcess Size\n");
for(i=0;i<m;i++)
{
printf("\n%d\t\t%d",i+1,b[i]);
if(mem[i]==1)
printf("\t\t\t%d\t\t\t%d",t[i]+1,p[t[i]]);
else
printf("\t\tNot Allocated");
}
}