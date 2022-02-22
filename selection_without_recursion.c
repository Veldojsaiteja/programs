#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
 void selection_sort(int *a, int n)
 {
   int temp = 0, index = 0, min = 0;
   for(int i = 0; i<n; i++)
   {
     min = a[i];
     for(int j = i; j<n; j++)
     {
       if(min >= a[j])
       {
         min = a[j];
         index = j;
       }
     }
     temp = a[i];
     a[i] = min;
     a[index] = temp;
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
  selection_sort(p,n);
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
