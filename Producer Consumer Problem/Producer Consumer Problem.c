#include<stdio.h>
int empty, current_items=0, buff;
int wait(int s);
int signal(int s);
void produce();
void consume();

void main()
{
    int mutex=1, o;
    printf("Enter the size of the buffer: ");
    scanf("%d", &buff);
    empty=buff;
    while(o!=4)
    {
        printf("1.Produce 2.Consume 3.Print Buffer 4.Exit\nEnter the option number:");
        scanf("%d", &o);
        switch(o)
        {
            case 1:
            mutex=wait(mutex);
            produce();
            mutex=signal(mutex);
            break;
            case 2:
            mutex=wait(mutex);
            consume();
            mutex=signal(mutex);
            break;
            case 3:
            printf("Buffer details\n");
            printf("Current Items: %d",current_items);
            printf("Empty Spaces: %d",empty);
            break;
            case 4:
            break;
            default:
            printf("Invalid Choice");
            break;
        }
    }
}

int wait(int s)
{
    while(s==0);
    s=0;
    return s;
}

int signal(int s)
{
    s=1;
    return s;
}

void produce()
{
    int n;
    if(empty==0)
    {
        printf("Buffer is full\n");
    }
    else
    {
        printf("Enter the number of items to produce: ");
        scanf("%d",&n);
        if((current_items+n)<=buff)
        {
            current_items=current_items+n;
            empty=empty-n;
        }
        else
        {
            printf("Cannot produce\n");
        }
    }
}

void consume()
{
    int n;
    if(empty==buff)
    {
        printf("Buffer is empty\n");
    }
    else
    {
        printf("Enter the number of items to consume:");
        scanf("%d",&n);
        if(n<=current_items)
        {
            current_items=current_items-n;
            empty=empty+n;
        }
        else
        {
            printf("Cannot consume\n");
        }
    }
}