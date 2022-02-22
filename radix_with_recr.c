#include<stdio.h>
#include<conio.h>
void countSort(int a[],int n,int divv,int q,int max)
{
    int cnt[10],temp[n],i;
    for(i=0;i<10;i++)cnt[i]=0;
    //Increment the values based on the  place value
    for(i=0;i<n;i++) cnt[(a[i]/divv)%10]++;
    //Cumulative addition fot the purpose of placing the elements in the temp array
    for(i=1;i<10;i++) cnt[i]=cnt[i-1]+cnt[i];
    //Placing the elements in the array
    for(i=n-1;i>=0;i--)
    {
        temp[cnt[(a[i]/divv)%10]-1]=a[i];
        cnt[(a[i]/divv)%10]--;
    }
    //shifting the elements in the temp array to the initial array
    for(i=0;i<n;i++) a[i]=temp[i];
    divv*=10;
    q=max/divv;
    if(q>0) countSort(a,n,divv,q,max);

}
void radixSort(int a[],int n)
{
    int max,i,q;
    max=a[0];
    for(i=1;i<n;i++)
        {
            if(a[i]>max) max=a[i];
        }
    i=1;
    q=max/i;
    countSort(a,n,i,q,max);
}
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    if(n<=0) printf("Array size is invalid.");
    else
    {
        printf("Enter %d elements : ",n);
        int a[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        radixSort(a,n);
        printArray(a,n);
    }
    getch();
    return 0;
}
