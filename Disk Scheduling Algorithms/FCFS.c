#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r,s,h,i,q[25],seek=0,diff=0;
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
        scanf("%d",&q[i]);
    }
    q[0]=h;
    for(i=0;i<s;i++)
    {
        diff=abs(q[i+1]-q[i]);
        seek=seek+diff;
        printf("Seek time from %d to %d: %d\n",q[i+1],q[i],diff);
    }
    printf("Total seek time: %d\n",seek);
    avg=seek/s;
    printf("Average seek time: %f",avg);
}