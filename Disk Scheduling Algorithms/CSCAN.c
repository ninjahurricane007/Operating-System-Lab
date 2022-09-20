#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r,s,h,i,j,q[25],seek=0,diff=0,temp,temp1=0,temp2=0,q1[25],q2[25];
    float avg;
    printf("Enter the disk range:");
    scanf("%d",&r);
    printf("Enter the size of request queue:");
    scanf("%d",&s);
    printf("Enter the starting position:");
    scanf("%d",&h);
    printf("Enter the request array\n");
    for(i=1;i<=s;i++)
    {
        scanf("%d",&temp);
        if(temp>h)
        {
            q1[temp1]=temp;
            temp1++;
        }
        else
        {
            q2[temp2]=temp;
            temp2++;
        }
    }
    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(q1[i]>q1[j])
            {
                temp=q1[i];
                q1[i]=q1[j];
                q1[j]=temp;
            }
        }
    }
    for(i=0;i<temp2-1;i++)
    {
        for(j=i+1;j<temp2;j++)
        {
            if(q2[i]>q2[j])
            {
                temp=q2[i];
                q2[i]=q2[j];
                q2[j]=temp;
            }
        }
    }
    for(i=1,j=0;j<temp1;i++,j++)
    {
        q[i]=q1[j];
    }
    q[i]=r;
    q[i+1]=0;
    for(i=temp1+3,j=0;j<temp2;i++,j++)
    {
        q[i]=q2[j];
    }
    q[0]=h;
    for(i=0;i<=s+1;i++)
    {
        diff=abs(q[i+1]-q[i]);
        seek=seek+diff;
        printf("Seek time from %d to %d: %d\n",q[i+1],q[i],diff);
    }
    printf("Total seek time: %d\n",seek);
    avg=seek/s;
    printf("Average seek time: %f",avg);
}