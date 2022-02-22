#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct stack
{
    int *a;
    int top,MAX;
}STACK;

void push(int *a, int data, int size,int *top)
{
      if (*top == size - 1)
        printf("Stack Overflow!!");
      else
      {
        (*top)++;
        a[*top] = data;
        printf("Pushed succesfully!!");
      }
}

void pop(int *top)
{
  if (*top == -1)
    printf("Stack Underflow!!");
  else {
  (*top)--;
    printf("Poped succesfully!!");
  }
}

void display(int *a,int *top)
{
  if (*top == -1)
    printf("Stack is Empty!!");
  else
  {
    printf("Elements in stack are : ");
    for (int i = *top; i >= 0; i--)
    {
      printf(" %d", a[i]);
    }
  }
}

int top_of_stack(int *a,int *top)
{
  if (*top == -1)
    printf("Stack is Empty!!");
  else
    printf("Top of stack element : %d", a[*top]);
}

int main()
{
  int choice, input;
  STACK.top = -1;
  printf("Enter the size of stack : ");
  scanf("%d", &STACK.MAX);
  if (STACK.MAX <= 0)
   {
    printf("Invalid size !!\n");
  }
  else
  {
    STACK.a = (int*)malloc(STACK.MAX*sizeof(int));
    while (1)
     {
      printf("\n---------------------------\n");
      printf("1.PUSH\n2.POP\n3.DISPLAY\n4.TOP OF STACK\n5.EXIT");
      printf("\n---------------------------\n");
      printf("enter your choice : ");
      scanf("%d", &choice);
      switch (choice)
      {
          case 1:
            printf("Enter the element : ");
            scanf("%d", &input);
            push(STACK.a, input, STACK.MAX,&STACK.top);
            break;
          case 2:
            pop(&STACK.top);
            break;
          case 3:
            display(STACK.a,&STACK.top);
            break;
          case 4:
            top_of_stack(STACK.a,&STACK.top);
            break;
          case 5:
            free(STACK.a);
            getch();
            return 0;
          default:
            printf("Invalid operation!!");
            break;
      }
    }
  }
}
