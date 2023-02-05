#include<stdio.h>
#include<stdio.h>
#define SIZE 10
int stack[SIZE],top=-1;
void push(int data)
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow.");
    }
    else
    {
        stack[++top]=data;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow.");
    }
    else
    {
        return stack[top--];
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
    for(i=0;i<=top;i++)
    {
        printf("%d",stack[i]);
    }    
    return 0;
}