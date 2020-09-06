#include<stdio.h>
#include<stdlib.h>

void swap(int *p1,int *p2)
{
    int tmp;
    tmp=*p2;
    *p2=*p1;
    *p1=tmp;
}

void heapify(int a[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int tmp=i;

    if(left<n && a[left]>a[tmp])
        tmp=left;
    if(right<n && a[right]>a[tmp])
        tmp=right;

    if(tmp!=i)
    {
        swap(&a[i],&a[tmp]);
        heapify(a,n,tmp);
    }
}

void heap_sort(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

void print(int a[], int n)
{
      int i;
    for (i=0; i<n; ++i)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int a[]={1,99,8,6,2,0,7,6,5};
    print(a,9);
    heap_sort(a,9);
    print(a,9);
}
