#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 20
int top,stack[MAX];
char infix[MAX],postfix[MAX];
int empty()
{
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int symbol)
{
    if (top >=MAX)
    {
        printf("\nOverflow");
        return;
    }
    stack[++top] = symbol;
}
int pop()
{
    if (empty())
    {
        printf("\nUnderflow");
        exit(1);
    }
    else
    {
        return (stack[top--]);
    }
}
int priority(char symbol)
{
    switch (symbol)
    {
        case '(':
        return 0;
        break;
        case '+':
        case '-':
        return 1;
        break;
        case '*':
        case '/':
        case '%':
        return 2;
        break;
        case '^':
        return 3;
        break;
        default:
        return 0;
    }
}
void infixtopostfix()
{
    int i, p = 0;
    char next, symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
            case '(':
            push(symbol);
            break;
            case ')':
            while ((next = pop()) != '(')
            {
                postfix[p++] = next;
            }
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            while((!empty())&&(priority(stack[top])>=priority(symbol)))
            {
                postfix[p++]=pop();
            }
            push(symbol);
            break;
            default:
            postfix[p++]=symbol;
            break;
        }
    }
    while(!empty())
    {
        postfix[p++]=pop();
    }
    postfix[p]='\0';
}
int evaluation()
{
    int a,b,temp,result,i;
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
        {
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                temp=b+a;
                break;
                case '-':
                temp=b-a;
                break;
                case '*':
                temp=b*a;
                break;
                case '/':
                temp=b/a;
                break;
                case '%':
                temp=b%a;
                break;
                case '^':
                pow(b,a);
            }
            push(temp);
        }
    }
    result =pop();
    return result;
}
int main()
{
    top=-1;
    printf("Enter the infix expression : ");
    gets(infix);
    infixtopostfix();
    printf("The postfix expression is : ");
    printf("%s",postfix);
    printf("\nThe value is : ");
    printf("%d",evaluation());
    return 0;
}