#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
    int coef,expo;
    struct polynomial *link;
};
struct polynomial *insert(struct polynomial *start,int c,int e)
{
    struct polynomial *temp,*q;
    temp=(struct polynomial *)malloc(sizeof(struct polynomial));
    temp->coef=c;
    temp->expo=e;
    if(start==NULL || e>start->expo)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
        q=start;
        while(q->link!=NULL && e<=q->link->expo)
        {
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;       
    }
    return start;
}
void display(struct polynomial *q)
{
    while(q!=NULL)
    {
        printf(" %dx^%d ",q->coef,q->expo);
        if(q->link!=NULL)
        {
            printf("+");
        }
        else
        {
            printf("\n");
        }
        q=q->link;
    }
}
void add(struct polynomial *a,struct polynomial *b)
{
    struct polynomial *start3;
    start3=NULL;
    while(a!=NULL && b!=NULL)
    {
        if(a->expo>b->expo)
        {
            start3=insert(start3,a->coef,a->expo);
            a=a->link;
        }
        else if(a->expo<b->expo)
        {
            start3=insert(start3,b->coef,b->expo);
            b=b->link;
        }
        else if(a->expo==b->expo)
        {
            start3=insert(start3,a->coef+b->coef,a->expo);
            a=a->link;
            b=b->link;
        }
    }
    while(a!=NULL)
    {
        start3=insert(start3,a->coef,a->expo);
        a=a->link;
    }
    while(b!=NULL)
    {
        start3=insert(start3,b->coef,b->expo);
        b=b->link;
    }
    display(start3);
}
struct polynomial *create(struct polynomial *start)
{
    int n,e,c;
    printf("Enter no. of terms in the polynomial : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter coefficient and exponent : ");
        scanf("%d %d",&c,&e);
        start=insert(start,c,e);
    }
    return start;
}
void multiply(struct polynomial *a,struct polynomial *b)
{
    struct polynomial *start4=NULL,*b_beg=b;
    while(a!=NULL)
    {
        b=b_beg;
        while(b!=NULL)
        {
            start4=insert(start4,a->coef*b->coef,a->expo+b->expo);
            b=b->link;
        }
        a=a->link;
    }
    display(start4);
}
void main()
{
    struct polynomial *start1=NULL,*start2=NULL;
    start1=create(start1);
    start2=create(start2);
    printf("First polynomial : ");
    display(start1);
    printf("\nSecond polynomial : ");
    display(start2);
    printf("\nThe addition is : ");
    add(start1,start2);
    printf("\nThe multiplication is : ");
    multiply(start1,start2);
}