#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}*front=NULL,*rear=NULL;
void insert (int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(front==NULL)
    {
        front=temp;
    }
    else
    {
        rear->link=temp;
    }
    rear=temp;
}
void delete()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Underflow.");
        return;
    }
    else
    {
        temp=front;
        front=front->link;
        free(temp);
    }
}
void display()
{
    struct node *q;
    q=front;
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->link;
    }
}
int main()
{
    int c,e,n,i;
    while(1)
    {
        printf("\n0.Exit.\n1.Input element to queue.\n2.Delete element from queue.\n3.Display queue.\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter no. of elements to be inserted : ");
            scanf("%d",&n);
            printf("Enter elements : ");
            for(i=0;i<n;i++)
            {
               scanf("%d",&e);
               insert(e);
            }
            break;
            case 2:
            delete();
            break;
            case 3:
            printf("\nThe queue is : ");
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