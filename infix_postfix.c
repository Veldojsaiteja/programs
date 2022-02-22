#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
struct Stack
{
	char *s;
	int TOP,MAX;
}S;

int operPrec(char c)
{
	switch(c)
	{
		case '^': return 3;
		case '%':
		case '/':
		case '*': return 2;
		case '+':
		case '-': return 1;
	}
	return -1;
}

void infixToPostFix(char *a)
{
	S.MAX = strlen(a);
	S.TOP = -1;
	S.s = (char *)malloc(S.MAX * sizeof(char));
	for(int i=0;a[i] != '\0';i++)
	{
		if(isalpha(a[i]) || isdigit(a[i])) printf("%c",a[i]);
		else if(a[i] == '(')
		{
			if(S.TOP != S.MAX-1) S.s[++S.TOP] = a[i];
		}
		else if(a[i] == ')')
		{
			while(S.s[S.TOP] != '(')
			{
				printf("%c",S.s[S.TOP]);
				S.TOP--;
			}
			S.TOP--;
		}
		else
		{
			while(operPrec(S.s[S.TOP]) >= operPrec(a[i]))
			{
				printf("%c",S.s[S.TOP--]);
			}
			S.s[++S.TOP] = a[i];
		}
	}
	while(S.TOP != -1) printf("%c",S.s[S.TOP--]);
}
int main()
{
	char a[25];
	printf("Enter infix Expression :");
	scanf("%s",a);
	infixToPostFix(a);
  getch();
	return 0;
}
