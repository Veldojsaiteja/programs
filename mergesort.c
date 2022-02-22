//merge sort using iteration
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void merge(int* a,int low, int mid,int high)
{
int temp[high], count = low, i,j;
for(i = low, j = mid+1; i <= mid && j<=high;)
{
if(a[i] >= a[j]){
temp[count++] = a[j++];
continue;}
else{
temp[count++] = a[i++];
continue;}
}
while(i<=mid){
  temp[count++] = a[i++];
}
while(j<=high){
  temp[count++] = a[j++];
}
for(int k = low; k<count;k++)
{
  a[k] = temp[k];
}
}
void sort(int* a,int low, int high)
{
int mid;
if(low < high)
{
mid = (low+high)/2;
sort(a,low,mid);
sort(a,mid+1,high);
//merging
merge(a,low,mid,high);
}

}
int main()
{
  int *p, n;
  printf("enter the size of an array : ");
  scanf("%d",&n);
  if(n > 0){
  p = (int*)malloc(n * sizeof(int));
    printf("enter the element : ");
  for(int i = 0; i<n; i++)
  {
    scanf("%d",p+i);
  }
  sort(p,0,n-1);
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
