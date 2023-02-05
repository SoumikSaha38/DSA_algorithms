#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start,*top;
void push(int data)
{
    struct node *p,*temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->info=data;
    if(start==NULL)
    {
        start=temp;
        top=temp;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        top=temp;
    }
}
int pop()
{
    struct node *p,*temp;
    if(top==NULL)
    {
        printf("Stack Underflow.");
    }
    else
    {
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        temp=p->next;
        return p->next->info;
        free(temp);
        top=p;
    }
}
int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        push(i);
    }
    pop();
    pop();
    push(1);
}