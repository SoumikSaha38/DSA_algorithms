#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int expo;
    struct node *link;
}*start1,*start2,*start3;
struct node* create(int co,int ex,struct node *start)
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coef=co;
    temp->expo=ex;
    if(start==NULL || ex>start->expo)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
        q=start;
        while(q->link!=NULL && ex<q->expo)
        {
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;
    }
    return start;
}
void display(struct node *start)
{
    if(start==NULL)
    {
        printf("The linked list is empty.");
        return;
    }
    else
    {
        struct node *q;
        q=start;
        while(q!=NULL)
        {
            printf("+ %dx^%d ",q->coef,q->expo);
            q=q->link;
        }
    }
}
int add()
{
    struct node *p=start1,*q=start2;
    while(q!=NULL && p!=NULL)
    {
        if(p->expo==q->expo)
        {
            start3=create(p->coef+q->coef,p->expo,start3);
            q=q->link;
            p=p->link;
        }
        else if(p->expo>q->expo)
        {
            start3=create(p->coef,p->expo,start3);
            p=p->link;
        }
        else if(q->expo>p->expo)
        {
            start3=create(q->coef,q->expo,start3);
            q=q->link;
        }
    }
    while(q!=NULL)
    {
        start3=create(q->coef,q->expo,start3);
    }
    while(p!=NULL)
    {
        start3=create(p->coef,p->expo,start3);
    }
    display(start3);
}
void multiply(struct node *a,struct node *b)
{
    struct node *start4=NULL,*b_beg=b;
    while(a!=NULL)
    {
        b=b_beg;
        while(b!=NULL)
        {
            start4=create(start4,a->coef*b->coef,a->expo+b->expo);
            b=b->link;
        }
        a=a->link;
    }
    display(start4);
}
int main()
{
    start1=start2=start3=NULL;
    start1=create(5,4,start1);
    start1=create(5,3,start1);
    start1=create(5,2,start1);
    start2=create(6,7,start2);
    start2=create(7,5,start2);
    start2=create(6,4,start2);
    display(start1);
    printf("\n");
    display(start2);
    add();
    multiply(start1,start2);
    return 0;
}