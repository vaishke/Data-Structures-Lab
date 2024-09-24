#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char s[100];
char st[100];
int j = -1;

int priority(char);

int main()
{
	printf("Enter an infix expression: ");
	gets(s);
	int i=0;
	while(i != strlen(s))
	{
		if(isdigit(s[i]))
		{
			printf("%c",s[i]);
		}
		else if(s[i] == '(')
		{
			j=j+1;
			st[j] = '(';
		}
		else if(s[i]==')')
		{
			while(st[j]!='(')
			{
				printf("%c",st[j]);
				j=j-1;
			}
			j=j-1;
		}
		else{
			if (priority(st[j]) < priority(s[i]))
			{
				j=j+1;
				st[j]=s[i];
			}
			else if(priority(st[j])>=priority(s[i]) )
			{
				if (priority(st[j]) == 3 && priority(s[i])== 3)
				{
					j=j+1;
					st[j] = '^';
				}
				else{
					while(priority(st[j])>=priority(s[i]))
					{
						printf("%c",st[j]);
						j=j-1;
					}	
					j=j+1;
					st[j]=s[i];	
				}		
			}	
		}
		i++;
	}
	while(j>=0)
	{
		printf("%c",st[j]);
		j--;			
	}	
}
int priority(char d)
{
	if(d == '+')
		return(1);
	if(d == '-')
		return(1);
	if(d == '*')
		return(2);
	if(d == '/')
		return(2);
	if(d == '%')
		return(2);
	if(d == '^')
		return(3);
	if(d == '(')
		return(0);
}
