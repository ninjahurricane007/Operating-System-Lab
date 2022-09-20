

#include<stdio.h>

int main()
{
int n,i,j,bt[25],wt[25],tt[25],temp,ttt=0,twt=0;
float att, awt;
printf("Enter the no. of processes:");
scanf("%d",&n);
printf("\nEnter the burst time of processes\n");
for (i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(bt[j]>bt[j+1])
{
temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;
}
}
}
wt[0]=0;
for (i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
twt=twt+wt[i];
}
awt=twt/n;
for (i=0;i<n;i++)
{
tt[i]=wt[i]+bt[i];
ttt=ttt+tt[i];
}
att=ttt/n;
printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
for (i=0;i<n;i++)
{
printf("p%d\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tt[i]);
}
printf("\nAverage waiting time=%f\n\n",awt);
printf("Average turn around time=%f\n\n",att);
}
