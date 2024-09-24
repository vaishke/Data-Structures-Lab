#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int priority(char);
char re[100];
char st[100];
int j=-1;
int main()
{
	printf("Enter an infix expression: ");
	gets(re);
	int l=strlen(re);
	int i=0;
	char s[l];
	char dup[l];
	int du = 0;
	for(int k = l-1; k>=0; k--)
	{
		s[i] = re[k];
		i++;
	}
	i=0;
	while(i != l)
	{
		if(isdigit(s[i]))
		{
			dup[du] = s[i];
			du++;
		}
		else if(s[i] == ')')
		{
			j=j+1;
			st[j] = ')';
		}
		else if(s[i]=='(')
		{
			while(st[j]!=')')
			{
				dup[du] = st[j];
				du++;
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
			else if(priority(st[j])>=priority(s[i]))
			{
				if(priority(st[j]) == priority(s[i]) )
				{
					j=j+1;
					st[j] = s[i];
				}
				else{
					while(priority(st[j])>priority(s[i]))
					{
						dup[du] = st[j];
						du++;
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
		dup[du] = st[j];
		du++;
		j--;			
	}
	for(int m = l-1; m>=0;m--)
	{
		printf("%c",dup[m]);
	}	
}
int priority(char d)
{
	if(d == '+')
	{
		return(1);
	}
	if(d == '-')
	{
		return(1);
	}
	if(d == '*')
	{
		return(2);
	}
	if(d == '/')
	{
		return(2);
	}
	if(d == '%')
	{
		return(2);
	}
	if(d == '^')
	{
		return(3);
	}
	if(d == ')')
	{
		return(0);
	}
}