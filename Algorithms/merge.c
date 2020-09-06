#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int l ,int m,int r)
{
  int tmp[r-l+1];
  int k=0,i=0;
  int p=l,q=m+1;
  for(i=l;i<=r;i++,k++)
  {
      if(p>m)
        tmp[k]=a[q++];
      else if(q>r)
        tmp[k]=a[p++];
      else if(a[p]<a[q])
        tmp[k]=a[p++];
      else
        tmp[k]=a[q++];
  }
  for(i=0;i<k;i++)
    a[l++]=tmp[i];
}

void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
    int m=l+(r-l)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);

    merge(a,l,m,r);
    }
}

void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int a[]={5,2,9,56,123,1,0};
     print(a,7);
     merge_sort(a,0,6);
     print(a,7);
}
