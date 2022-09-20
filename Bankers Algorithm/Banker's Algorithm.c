#include<stdio.h>
void main()
{
    int i, j, k, n, m, p=0, flag;
    printf("Enter the no. of processes:");
    scanf("%d",&n);
    printf("Enter the no. of resourses:");
    scanf("%d",&m);
    int max[n][m], alloc[n][m], need[n][m], safe[n], f[n], avail[m];
    printf("Enter the elements to max matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the elements to allocation matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the elements to available matrix\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        f[i]=0;
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    safe[p]=i;
                    p++;
                    for(j=0;j<m;j++)
                    {
                        avail[j]+=alloc[i][j];
                    }
                    f[i]=1;
                }
            }
        }
    }
    if(p<n)
    {
        printf("System is not in safe state");
    }
    else
    {
        printf("System is in safe state\n");
        printf("Safe sequence\n");
        for(i=0;i<n;i++)
        {
            printf("P->%d",safe[i]);
        }
    }
}
