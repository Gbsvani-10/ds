#include<stdio.h>
#include<ctype.h>
#include<math.h>
//#define MAX 100
int stack[100];
int top=-1;
void push(int value)
{
	stack[++top]=value;
}
int pop()
{
	return stack[top--];
}
int main()
{
	char postfix[100];
	int i=0,a,b,result;
	printf("\n enter postfix expresion:");
	//scanf("%s",postfix);
	fgets(postfix,sizeof(postfix),stdin);
	//for(i=0;postfix[i]!='\0';i++)
	while(postfix[i]!='\0')
	{
		if(isdigit(postfix[i]))
		{
			push(postfix[i]-'0');
		}
		else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^'||postfix[i]=='$')
		{
				b=pop();
				a=pop();
				switch(postfix[i])
				{
					case '+':
						push(a+b);
						break;
					case '-':
						push(a-b);
						break;
					case '*':
						push(a*b);
						break;
					case '/':
						push(a/b);
						break;
					case '$':
					case '^':
						push(pow(a,b));
						break;
					default:
						printf("invalid choice");
				}
		}
		i++;
	}
	result=pop();
	printf("result:%d",result);
	return 0;
}
