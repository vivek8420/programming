/*
*   author:vivek8420
*  binary index tree with offline query
*  KQUERY-SPOJ
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define PI pair<int,int>
#define MAX 111111
#define MOD 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

struct node {
    int pos;
    int l;
    int r;
    int val;
};

bool comp(node a, node b)
{
    if (a.val == b.val)
        return a.l > b.l;
    return a.val > b.val;
}

int BIT[MAX];

void update(int n, int idx,int val)
{
    while (idx <= n) {
        BIT[idx]+=val;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int ans = 0;
    while (idx) {
        ans += BIT[idx];

        idx -= idx & (-idx);
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int n;
    scanf("%d",&n);
    ll a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int q;
    scanf("%d",&q);
     node kquery[n+q+1];
    for(int i=1;i<=n;i++)
    {
        kquery[i].val=a[i];
        kquery[i].pos=0;
        kquery[i].l=0;
        kquery[i].r=i;
    }

    for(int i=1;i<=q;i++)
    {
        kquery[n+i].pos=i;
        scanf("%d %d %d",&kquery[n+i].l,&kquery[n+i].r,&kquery[n+i].val);
    }

    sort(kquery+1,kquery+n+q+1,comp);
    int ans[q+1];

    for(int i=1;i<=n+q;i++)
    {
        if(kquery[i].pos==0)
        {
            update(n,kquery[i].r,1);
        }
        else
        {
            int cnt=query(kquery[i].r)-query(kquery[i].l-1);
            ans[kquery[i].pos]=cnt;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
}
