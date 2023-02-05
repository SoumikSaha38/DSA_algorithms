#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*last;

void create(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(last==NULL)
    {
        last=temp;
        last->next=last;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}

void display()
{
    struct node *p;
    p=last->next;
    while(p!=last)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("%d ",last->info);
}

void insretbeg(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=last->next;
    last->next=temp;
}

void position(int data,int pos)
{
    struct node *p=last,*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(pos!=0)
    {
        for(int i=0;i<pos;i++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

void delete(int data)
{
    struct node *temp,*p=last;
    if(last->next->info==data)
    {
        temp=last->next;
        last->next=temp->next;
        free(temp);
    }
    else
    {
        while(p->next->next!=last)
        {
            if(p->next->info==data)
            {
                temp=p->next;
                p->next=temp->next;
                free(temp);
            }
        }
    }
    if(p->next->next==last)
    {
        p->next=last->next;
        free(last);
        last=p;
    }
}

/*void reverse()
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
}*/

int main()
{
    last=NULL;
    create(1);
    insretbeg(2);
    create(3);
    create(4);
    display();
    delete(3);
    display();
}