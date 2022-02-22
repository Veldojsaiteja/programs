#include<stdio.h>
#include<conio.h>
int main()
{
  int n,min,max;
  printf("enter the size of array  :");
  scanf("%d",&n);
  int arr[n];
  printf("enter the elements : ");
  for(int i = 0; i<n ;i++)
    scanf("%d",&arr[i]);
  min = arr[0]; max = arr[0];
  for(int i = 0; i<n; i++)
  {
    if(min > arr[i])
      min = arr[i];
    if(max < arr[i])
      max = arr[i];
  }
  if(min%2 == 0)
    printf("%d Minimum Number, and it is Even\n",min);
  else
    printf("%d Minimum Number, and it is Odd\n",min);
  if(max%2 == 0)
    printf("%d Maximum Number, and it is Even",max);
  else
    printf("%d Maximum Number, and it is Odd",max);
}
