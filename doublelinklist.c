#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;

void create(int data)
{
    struct node *p,*temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->info=data;
    if(start==NULL)
    {
        start=temp;
        temp->prev=NULL;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
}

void display()
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}

void insretbeg(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}

void position(int data,int pos)
{
    struct node *p=start,*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(pos!=0)
    {
        for(int i=0;i<pos;i++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
        temp->prev=p;
    }
}

void delete(int data)
{
    struct node *temp,*p=start;
    if(start->info==data)
    {
        temp=start;
        start=start->next;
        start->prev=NULL;
    }
    else
    {
        while(p->next->next!=NULL)
        {
            if(p->next->info==data)
            {
                temp=p->next;
                p->next=temp->next;
                temp->next->prev=p;
                free(temp);
            }
            p=p->next;
        }
    }
    if(p->next->info==data)
    {
        temp=p->next;
        p->next=NULL;
        free(temp);
    }
}

void reverse()
{
    struct node *p1,*p2,*p3;
    p1=NULL;
    p3=p2=start;
    while(p3!=NULL)
    {
        p3=p3->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }
    start=p1;
}

int main()
{
    start=NULL;
    create(1);
    insretbeg(2);
    create(3);
    create(4);
    create(5);
    display();
    printf("\n");
    delete(4);
    display();
}