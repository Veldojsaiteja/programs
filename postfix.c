#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include "stack.h"
#include<conio.h>
struct Stack
{
	int *a;
	int TOP,MAX;
}S;

int postFixEval(char *s)
{
	S.MAX = strlen(s);
	S.TOP = -1;
	S.a = (int *)malloc(S.MAX * sizeof(int));
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i] == ' ') continue;
		else if(isdigit(s[i]))
		{
			int n = 0;
			while(isdigit(s[i]))
			{
				n = n*10 + (int)s[i] - '0';
				i++;
			}
			i--;
			push(S.a,n,S.MAX,&S.TOP);
		}
		else
		{
			int b = pop(S.a,&S.TOP);
			int a = pop(S.a,&S.TOP);
			switch(s[i])
			{
				case '+':
					push(S.a,a+b,S.MAX,&S.TOP);
					break;
				case '-':
					push(S.a,a-b,S.MAX,&S.TOP);
					break;
				case '*':
					push(S.a,a*b,S.MAX,&S.TOP);
					break;
				case '/':
					push(S.a,a/b,S.MAX,&S.TOP);
					break;
				case '^':
					push(S.a,(int)pow(a,b),S.MAX,&S.TOP);
					break;
			}
		}
	}
	return pop(S.a,&S.TOP);
}
int main()
{
	char s[25];
	printf("Enter PostFix Exp:");
	scanf("%[^\n]s",s);
	int res = postFixEval(s);
	printf("Result : %d",res);
  getch();
	return 0;
}
