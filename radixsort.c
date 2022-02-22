#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void radix_sort(int* p, int n, int div)
{
  int queue[10][n], count = 0;
  int point[10] = {0,0,0,0,0,0,0,0,0,0};
  for(int i = 0; i<n; i++)
  {
    queue[(p[i]/div)%10][point[(p[i]/div)%10]++] = p[i];
  }
  for(int i = 0; i<10; i++)
  {
    for(int j = 0; j< point[i];j++)
      p[count++] = queue[i][j];
  }
}

int main()
{
  int *p, n, max, count = 1;
  printf("enter the size of an array : ");
  scanf("%d",&n);
  if(n > 0){
  p = (int*)malloc(n * sizeof(int));
  printf("enter the element : ");
  for(int i = 0; i<n; i++)
  {
    scanf("%d",p+i);
  }
  max = p[0];
  for(int i = 0; i<n; i++)
  {
    if(max < p[i])
      max = p[i];
  }
    while(max > 0)
    {
      max = max/10;
     radix_sort(p,n, count);
      count = count * 10;
  }
  printf("SORTED ARRAY : ");
  for(int i = 0; i<n; i++)
  {
    printf(" %d", p[i]);
  }
  }
  else{ printf("invalid size!!\n"); getch();return 0;}
  getch();
  return 0;
}
