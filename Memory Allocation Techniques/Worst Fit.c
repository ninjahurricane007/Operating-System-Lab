#include <stdio.h>
#include <stdlib.h>
int p[10], r[10], i, j, temp,l=100,b=0;
int n, m,t[10],mem[10];

int main()
{
int p[10], b[10], i, j, temp,r=0;
int n, m,t[10],mem[10];
printf ("Enter the no of memory blocks:");
scanf ("%d", &m);
printf ("Enter the no of processes:");
scanf ("%d", &n);
printf ("Enter size of each memory block\n");
for (i = 1; i <= m; i++)
{
scanf ("%d", &b[i]);
}
printf ("Enter each process size\n");
for (i = 1; i <= n; i++)
{
scanf ("%d", &p[i]);
}

for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(mem[j]!=1)
{
temp=b[j]-p[i];
if(temp>=0)
if(temp>r)
{
t[i]=j;
r=temp;
}
}
}
mem[t[i]]=1;
r=0;
}
printf("\nMemory block\tMemory Size\tProcess no\t\tProcess Size");
for(i=1;i<=n && t[i]!=0;i++)
{
printf("\n%d\t\t %d\t\t %d\t\t\t %d",t[i],b[t[i]],i,p[i]);
}
}