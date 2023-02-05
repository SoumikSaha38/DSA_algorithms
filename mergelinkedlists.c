#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start1,*start2;
struct node *create(int data,struct node *start)
{
    struct node *p,*temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->info=data;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    return start;
}
void display(struct node *start)
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
void merge()
{
    struct node *p=start1,*q=start2,*r,*s;
    while(p!=NULL && q!=NULL)
    {
        r=p->next;
        p->next=q;
        s=q->next;
        if(!(s!=NULL&&r==NULL))
        {
            q->next=r;
        }
        q=s;
        p=p->next->next;
    }
}
int main()
{
    int i;
    start1=start2=NULL;
    for(i=0;i<=10;i=i+2)
    {
        start1=create(i,start1);
    }
    display(start1);
    printf("\n");
    for(i=1;i<10;i=i+2)
    {
        start2=create(i,start2);
    }
    display(start2);
    printf("\n");
    merge(start1,start2);
    display(start1);
}