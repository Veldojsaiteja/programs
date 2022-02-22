#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void quicksort(int* number,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot])
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
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
  quicksort(p,0,n-1);
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
