#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct stack
{
    int *a;
    int top,MAX;
}STACK, res_stack;

void pushingIntoStack(int* a, int* top, int max)
{
  for(int i = 0; i<max; i++){
      printf("Enter the element %d : ", i+1);
      scanf("%d", &a[++(*top)]);
    }
}
void splitStack(int* res, int* original, int* res_top, int ori_top)
{
  int count = 0;
  for(int i = ori_top; i>=0; i--)
  {
    if(original[i] < 0)
    {
      res[++(*res_top)] = original[i];
    }
    else count++;
  }
  for(int i = ori_top; i>=0; i--)
  {
    if(original[i] >= 0)
    {
      res[++(*res_top)] = original[i];
      count--;
    }
    if(count==0) break;
  }
}
void display(int* a, int top)
{
  printf("The elements in the result stack is : ");
  for(int i = top; i>=0; i--)
      printf("%d ", a[i]);
}
int main()
{
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
    //to push the elements
    pushingIntoStack(STACK.a, &STACK.top,STACK.MAX);
    //creating result stack
    res_stack.a = (int*)malloc(STACK.MAX*sizeof(int)); res_stack.top = -1;
    //to insert the elements as -ve -> +ve  order
    splitStack(res_stack.a,STACK.a,&res_stack.top,STACK.top);
    //displaying
    display(res_stack.a, res_stack.top);
    free(STACK.a);
    getch();
    return 0;
  }
}
