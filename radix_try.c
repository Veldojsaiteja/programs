#include<stdio.h>
void radix_sort(int* p, int n, int div)
{
  int count = 0, queue[10][n];
  int point[10] = {0,0,0,0,0,0,0,0,0,0};
  for(int i = 0; i<n; i++)
  {
    queue[(p[i]/div)%10][point[(p[i]/div)%10]++] = p[i];
  }
  for(int i = 0; i<10; i++)
  {
    for(int j = 0; j<point[i]; j++)
      p[count++] = queue[i][j];
  }
}
int main()
{
  int *p, n, max, count = 1;
  printf("enter the size of array : ");
  scanf("%d",&n);
  printf("enter the elements : ");
  for(int i = 0; i<n; i++)
  {
    scanf("%d",p+i);
  }
  max = p[0];
  for(int i = 0; i<n; i++)
  {
    if(max >= p[i])
      max = p[i];
  }
  while(max > 0)
  {
    radix_sort(p,n, count);
    count = count*10;
    max = max/10;
  }
  printf("sorted array : ");
  for(int i = 0; i<n; i++)
  {
    printf(" %d",p[i]);
  }
  return 0;
}
