#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50
int stack[MAX];
char postfix[20];
int top =-1;
void push(int item);
char pop();
void evaluate(char s);
int main()
{
	int i,n,x;
	char symbol;
	printf("Insert a profix notattion::\n");
	gets(postfix);
	n = strlen(postfix);
	for(i=0;i<n;i++)
	{
		symbol=postfix[i];
		if(symbol>='0'&&symbol<='9')
		{
			x=(int)(symbol-48);
			push(x);
		}
		else{
			evaluate(postfix[i]);
		}
	}
	printf("\n\nResult is ::%d",stack[top]);getch();
}
void push(int x)
{
	top++;
	stack[top]=x;
}
char pop()
{
	char x;
	x=stack[top];
	top--;
	return x;
}
void evaluate(char d)
{
	int a,b,c;
	a = pop();
	b = pop();
	switch(d)
	{
		case '+':
			c=a+b;
			top++;
			stack[top]=c;
			break;
		case'-':
			c=b-a;
			top++;
			stack[top]=c;
			break;
		case '*':
			c=b*a;
			top++;
			stack[top]=c;
			break;
		case '/':
			c=b/a;
			top++;
		case'%':
			c=a%b;
			break;
	}
	top++;
	stack[top]=c;
	c=0;
}