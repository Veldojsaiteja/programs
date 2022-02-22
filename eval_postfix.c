#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack
{
    int *a;
    int top,MAX;
}STACK;
void eval_postexp(char exp[], int len)
{
  STACK.MAX = len;
  STACK.top = -1;
  STACK.a = (int*)malloc(STACK.MAX*sizeof(char));
  char *ptr = strtok(exp, " ");
	while(ptr != NULL)
	{
    printf("%s",typeof(ptr));
    if(isdigit(ptr))
    {
      STACK.a[++top] = (int)ptr;
    }
    else{
    switch(ptr)
    {
      case '+':
            int a = STACK.a[top--];
            int b = STACK.b[top--];
            STACK.a[++top] = b+a;
            break;
      case '-':
            int a = STACK.a[top--];
            int b = STACK.b[top--];
            STACK.a[++top] = b-a;
            break;
      case '*':
            int a = STACK.a[top--];
            int b = STACK.b[top--];
            STACK.a[++top] = b*a;
            break;
     case '/':
            int a = STACK.a[top--];
            int b = STACK.b[top--];
            STACK.a[++top] = b/a;
            break;
     case '%':
            int a = STACK.a[top--];
            int b = STACK.b[top--];
            STACK.a[++top] = b%a;
            break;
     case '^':
            int a = STACK.a[top--];
            int b = STACK.b[top--];
            STACK.a[++top] = b^a;
            break;
    default:
            STACK.a[++top] = (int)ptr;
    }
  }
		ptr = strtok(NULL, " ");
	}
}
int main()
{
  char exp[50];
  printf("enter the postfix expression : ");
  scanf("%[^\n]", exp); // scanf reads till it enters the "ENTER" key.
  eval_postexp(exp, strlen(exp));
  return 0;
}
