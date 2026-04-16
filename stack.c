#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int stack[MAX];
int top=-1;
void push(int);
int pop();
void display();
int peek();
void push(int ele)
{
    if(top==MAX-1)
    {
        printf("Stack overflow");
    }
    else
    {
        top=top+1;
        stack[top] =ele; 
    }
}
int pop()
{
    int ele;
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        ele=stack[top];
        top=top-1;  
    }
    return ele;
}

int peek()
{
    int ele;
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        ele=stack[top];
    }
    return ele;
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}


int main()
{
    while(1)
    {
        int ch,ele;
        printf("\n1.Push\n2.Pop\n3.Display\n4.peek\n5.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Push");
                    printf("Enter element to push");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2:
                    ele=pop();
                    printf("Popped element is %d",ele);
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    ele=peek();
                    printf("Peek element is %d",ele);
                    break;
            case 5:
                    exit(0);
            default:
                    printf("Invalid choice");
                    break;
        }
    }
    

}
