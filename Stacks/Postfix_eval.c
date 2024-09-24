#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int top = 0;
int r;

int main()
{
	char post[30];
	int stack[30];
	int i;
	char num1,num2;
	printf("Enter postfix expression: ");
	scanf("%s", post);
	int l=strlen(post);
	for(i=0;i<l;i++)
	{
		if(post[i] == ',')
		{
			continue;
		}
		else if(post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^' || post[i] == '%')
		{
			top--;
			num1 = stack[top] ;
			top--;
			num2 = stack[top];
			char ch=post[i];
			switch(ch)
			{
				case '+':stack[top++] = num2 + num1;
						break;
				case '-' : stack[top++] = num2 - num1;
						break;
				case '*':stack[top++] = num2 * num1;
						break;
				case '/': stack[top++] = num2 / num1;
						break;
				case '^': stack[top++] = pow(num2,num1);
						break;
				case '%': stack[top++] = num2%num1;
						break;	
			}
		}
		else 
		{
			stack[top] = (int)post[i] - 48; 
			top++;
		}		
	}
	printf("%d",stack[0]); 
}