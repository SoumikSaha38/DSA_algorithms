//Implement DEqueue using array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int front=-1;
int rear=-1;
int dq[SIZE];
void insert_rear()
{
    int data;
    if ((front==0 && rear==SIZE-1)||(front==rear+1))
    {
        printf("OVERFLOW");
    }
    else
    {
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            if(rear==SIZE-1)
            {
                rear=0;
            }
            else
            {
                rear++;
            }
        }
        scanf("%d",&data);
        dq[rear]=data;
    }
}
void delete_front()
{
    if (front==-1)
    {
        printf("UNDERFLOW");
        return;
    }
    printf("the deleted element is %d", dq[front]);
    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if (front==SIZE-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
    }
}
void delete_rear()
{
    if (front==-1)
    {
        printf("UNDERFLOW");
        return;
    }
    printf("The deleted element is : %d ",dq[rear]);
    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(rear==0)
        {
            rear=SIZE-1;
        }
        else
        {
            rear--;
        }
    }
}
void insert_front()
{
    int data;
    if ((front==0 && rear==SIZE-1)||(front==rear+1))
    {
        printf("OVERFLOW");
        return;
    }
    if (front==-1)
    {
        front=0;
        rear=0;
    }
    else if (front==0)
    {
        front=SIZE-1;
    }
    else
    {
        front--;
        scanf("%d",&data);
        dq[front]=data;
    }
}
void display()
{
    int fp=front,rp=rear;
    if (fp<=rp)
    {
        while (fp<=rp)
        {
            printf(" %d ",dq[fp]);
            fp++;
        }
    }
    else
    {
        while (fp<SIZE)
        {
            printf(" %d ",dq[fp]);
            fp++;
        }
        fp=0;
        while (fp<=rp)
        {
            printf("%d",dq[fp]);
            fp++;
        }
    }
}
void inputDQ()
{
    int ch1;
    while(1)
    {
        printf("1.Insert at rear.\n2.Delete from front.\n3.Delete from rear.\n4.Display\nEnter your choice : ");
        scanf("%d",&ch1);
        switch (ch1)
        {
            case 1:
            insert_rear();
            break;
            case 2:
            delete_front();
            break;
            case 3:
            delete_rear();
            break;
            case 4:
            display();
            break;
            default:
            break;
        }
    }
}
void outputDQ()
{
    int ch2;
    while(1)
    {
        printf("0.Exit\n1.Insert at rear\n2.Delete from front.\n3.Insert at front.\n4.Display.\nEnter your choice : ");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1:
            insert_rear();
            break;
            case 2:
            delete_front();
            break;
            case 3:
            insert_front();
            break;
            case 4:
            display();
            break;
            case 0:
            exit(1);
            default:
            printf("Wrong input.");
            break;
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("1.Input restricted Double Ended Queue.\n2.Ouput Restricted Double Ended Queue.\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            inputDQ();
            break;
            case 2:
            outputDQ();
            break;
            default:
            printf("Wrong Input.");
            break;
        }
    }
}