#include<stdio.h>
int main()
{
int p,i,j,bt[25],at[25],wt[25],st[25],tat[25],ttat,twt,temp;
float atat=0.0,awt=0.0;
printf("Enter The no. of processes: ");
scanf("%d",&p);
printf("\nEnter the burst time of each processes\n");
for(i=0;i<p;i++)
{
scanf("%d",&bt[i]);
}
printf("\nEnter the arrival time of each processes\n");
for(i=0;i<p;i++)
{
scanf("%d",&at[i]);
}
printf("\nProcess\tBurst Time\tArrival Time\n");
for(i=0;i<p;i++)
{
printf("P%d\t%d\t\t%d\n",i,bt[i],at[i]);
}
for(i=0;i<p-1;i++)
{
for(j=0;j<p-i-1;j++)
{
if(at[j]>at[j+1])
{
temp=at[j];
at[j]=at[j+1];
at[j+1]=temp;
temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;
}
}
}
wt[0]=0;
tat[0]=wt[0]+bt[0];
for(i=1;i<p;i++)
{
st[i]=wt[i-1]+bt[i-1]+at[i-1];
wt[i]=st[i]-at[i];
tat[i]=wt[i]+bt[i];
awt=awt+wt[i];
atat=atat+tat[i];
}
awt=awt+wt[0];
awt=awt/p;
atat=atat+tat[0];
atat=atat/p;
printf("\nAfter FCFS\n");
printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\n");
for(i=0;i<p;i++)
{
printf("P%d\t%d\t\t%d\t\t%d\n",i,bt[i],at[i],wt[i]);
}
printf("\nAverage waiting time=%f\n",awt);
printf("\nAverage turnaround time=%f\n",atat);
}


