#include<stdio.h>

int binarySearch(int a[],int l,int r,int key)
{
    while(l<=r)
    {
      int m=l+(r-l)/2;

        if(a[m]==key)
            return m;
        else if(key<a[m])
          r=m-1;
        else
          l=m+1;
    }
    return -1;
}

int main()
{
   int a[]={1,2,3,4,5,6,7};
      int i= binarySearch(a,7,0);
      printf("%d",a[i]);
}
