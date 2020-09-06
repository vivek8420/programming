#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    int ansl[n+1],ansr[n+1];
    for(int maxi = 1;maxi<=30;maxi++){
        int last = 0;
        for(int i=1;i<=n;i++){
            if(last>=i || a[i]!=maxi)
                continue;
            int l=i,r=i;
            while(l>0 && a[l]<=maxi)
                l--;
            while(r<=n && a[r]<=maxi)
                r++;
            l++,r--;
            last = r;
            for(int j=l;j<=r;j++){
                if(a[j] == maxi){
                    ansl[j] = l;
                    ansr[j] = r;
                }
            }
        }   
    }

    while(q--) {
        int x;
        scanf("%d",&x);
        printf("%d %d\n",ansl[x],ansr[x]);
    }
}

