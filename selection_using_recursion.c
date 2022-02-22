#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
 void selection_rec(int index, int* a, int n)
{
  int min = index,temp = 0;
  if(index < n){
  for(int i = index; i<n; i++)
  {
    if(a[min] >= a[i])
    {
      min = i;
    }
  }
  temp = a[min];
  a[min] = a[index];
  a[index] = temp;
  selection_rec(index+1, a,n);
}
}
int main()
{
  int *p, n;
  printf("enter the size of an array : ");
  scanf("%d",&n);
  if(n > 0){
  p = (int*)malloc(n * sizeof(int));
  printf("enter the elements : ");
  for(int i = 0; i<n; i++)
  {
    scanf("%d",p+i);
  }
  selection_rec(0,p,n);
  printf("SORTED ARRAY : ");
  for(int i = 0; i<n; i++)
  {
    printf(" %d", p[i]);
  }
}
else{ printf("invalid size!!\n");getch();return 0;}
  getch();
  return 0;
}
