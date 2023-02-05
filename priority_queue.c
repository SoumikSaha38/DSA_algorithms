#include<stdio.h>
#include<stdlib.h>

struct node
{
    int priority,c;
    struct node *next;
}*start;

void insert(int data,int p){
    struct node *pr,*tmp;
    tmp=malloc(sizeof(struct node));
    tmp->c=data;
    tmp->priority=p;
    tmp->next=NULL;
    if (start==NULL||start->priority<p)
    {
        tmp->next=start;
        start=tmp;
        return;
    }
    pr=start;
    while (pr->next!=NULL&&pr->next->priority>p)
    {
        pr=pr->next;
    }
    tmp->next=pr->next;
    pr->next=tmp;
}

void display(){
    struct node *p=start;
    while (p!=NULL)
    {
        printf("%c %d--->",p->c,p->priority);
        p=p->next;
    }
    
}

void delete(){
    struct node *p=start;
    printf("\nThe deleted element is %c with priority %d",p->c,p->priority);
    start=start->next;
    free(p);
}

int main()
{
    start=NULL;
    int n,p;
    int d;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d",&d);
        insert(d,p);
    }
    display();
    delete();
    display();
    return 0;
}