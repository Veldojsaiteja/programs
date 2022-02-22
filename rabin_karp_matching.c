#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
int N, M;
char arr[100], pattern[100];
char *hash;
int h_size;
int hashtable_create()
{
  int sum = 0, temp = 0, k = 1, count = 0, flag =0;
  for(int i = 0; arr[i]!='\0'; i++)
  {
    for(int j = 0; hash[j]!='\0'; j++)
    {
      if(hash[j] == arr[i])
      {
        flag = 1;
        break;
      }
    }
    if(flag == 1) flag = 0;
    else
    {
      hash[count] = arr[i];
      count++;
    }
  }
  h_size = count;
  printf("---Hash Table---\n");
  for(int i = 0; hash[i]!='\0'; i++)
  {
    printf("%d -> %c\n",i,hash[i]);
  }
  for(int i = 0; i<M; i++)
    for(int j = 0; j < h_size; j++)
      if(hash[j] == pattern[i])
      {
        temp = pow(2, k++);
        sum += temp * j;
        break;
      }
  return sum;
}
int sum_of_hash(int index)
{
  int sum = 0, temp = 0, k = 1;
  for(int i = index; i< M + index; i++)
    for(int j = 0; j <h_size; j++)
      if(hash[j] == arr[i])
      {
        temp = pow(2, k++);
        sum += temp * j;
        break;
      }
  return sum;
}

void s_m(int pattern_sum)
{
    int count = 0;
    for(int i = 0; i< (N - M) + 1; i++)
    {
      if(sum_of_hash(i) == pattern_sum)
      {
        printf("element found at position : %d \n",i+1);
      }
      else count++;
    }
    if(count == (N - M)+1) printf("\nElement not found!!");
}
int main()
{
  printf("enter the string : ");
  scanf("%s", arr);
  printf("enter the pattern : ");
  scanf("%s", pattern);
  N = strlen(arr);
  M = strlen(pattern);
  hash = (char*)malloc(N*sizeof(char));
  int pattern_sum = hashtable_create();
  s_m(pattern_sum);
  return 0;
}
