// //implement queue using stack
// #include<stdio.h>
// #include<stdlib.h>


// struct node{
//     int data;
//     struct node *next;
// }*start[2];

// int isempty(int i){
//     if (start[i]==NULL)
//     {
//         return 1;
//     }
//     return 0;
// }

// void push(int data,int i){
//     struct node *p=malloc(sizeof(struct node));
//     p->data=data;
//     p->next=start[i];
//     start[i]=p;
// }

// int pop(int i){
//     if (start[i]==NULL)
//     {
//         return;
//     }
//     int a=start[i]->data;
//     struct node *p=start[i];
//     start[i]=start[i]->next;
//     free(p);
//     return a;
// }

// void enqueue(int data){
//     while (!isempty(0))
//     {
//         push(pop(0),1);
//     }
//     push(data,0);
//     while (!isempty(1))
//     {
//         push(pop(1),0);
//     }
// }

// void dequeue(){
//     if (start[0]==NULL)
//     {
//         return;
//     }
//     printf("%d ",pop(0));
// }



// int main()
// {
//     enqueue(1);
//     enqueue(2);
//     enqueue(3);
//     dequeue();
//     dequeue();
//     dequeue();
//     return 0;
// }

// //reversing queue
// #include<stdio.h>
// #include<stdlib.h>

// struct queue{
//     int data;
//     struct node *next;
// }*front,*rear;

// void enqueue(int data){
//     struct queue *p=malloc(sizeof(struct queue));
//     p->data=data;
//     p->next=NULL;
//     if (front==NULL)
//     {
//         front=p;
//         rear=p;
//         return;
//     }
//     rear->next=p;
//     rear=p;
// }

// int dequeue(){
//     if (front==NULL)
//     {
//         printf("No element");
//         return;
//     }
//     int a=front->data;
//     struct queue *p=front;
//     front=front->next;
//     free(p);
//     return a;
// }

// void reverse(){
//     if (front==NULL)
//     {
//         return;
//     }
//     int a=dequeue();
//     reverse();
//     enqueue(a);
// }

// void display(){
//     printf("\n");
//     struct queue *p=front;
//     while (p!=NULL)
//     {
//         printf("%d ",p->data);
//         p=p->next;
//     }
// }

// int main()
// {
//     int n,data;
//     scanf("%d",&n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&data);
//         enqueue(data);
//     }
//     display();
//     reverse();
//     display();
//     return 0;
// }

//implement stack using queue
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
}*front[2],*rear[2];

int isempty(int i){
    if (front[i]==NULL)
    {
        return 1;
    }
    return 0;
}


void enqueue(int data,int i){
    struct node *p=malloc(sizeof(struct node)),*q;
    p->data=data;
    p->next=NULL;
    if (front[i]==NULL)
    {
        front[i]=rear[i]=p;
        return;
    }
    rear[i]->next=p;
    rear[i]=p;
}

int dequeue(int i){
    if (!(front[i]==NULL))
    {
        struct node *p=front[i];
        int a=front[i]->data;
        front[i]=front[i]->next;
        free(p);
        return a;
    }
}


void push(int data){
    while (!isempty(0))
    {
        enqueue(dequeue(0),1);
    }
    enqueue(data,0);
    while (!isempty(1))
    {
        enqueue(dequeue(1),0);
    }
}

int pop(){
    if (!(front[0]==NULL))
    {
        printf("%d ",dequeue(0));
    }
}


int main()
{
    front[0]=rear[0]=front[1]=rear[1]=NULL;
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    pop();
    pop();
    return 0;
}