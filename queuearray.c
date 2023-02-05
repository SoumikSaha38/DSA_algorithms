#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
int front=-1;
int rear=-1;
int q[SIZE];
void insert(int data)
{
    if(rear==SIZE-1)
    {
        printf("Overflow");
        return;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        q[++rear]=data;
    }
}
void delete()
{
    if (front==-1||front>rear)
    {
        printf("Underflow.");
        return;
    }
    else
    {
        printf("Deleted element is : %d",q[front]);
        front++;
    }   
}
void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d",q[i]);
    }
}
int main()
{
    int c,e;
    while(1)
    {
        printf("\n0.Exit.\n1.Input element to queue.\n2.Delete element from queue.\n3.Display queue.\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter element to be inserted : ");
            scanf("%d",&e);
            insert(e);
            break;
            case 2:
            delete();
            break;
            case 3:
            printf("\nThe queue is :");
            display();
            break;
            case 0:
            exit(1);
            default:
            printf("Wrong input.");
            break;
        }
    }
    return 0;
}