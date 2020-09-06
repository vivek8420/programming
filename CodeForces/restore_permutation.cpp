/*
*   author:vivek8420
*   problem:D. Restore Permutation
*   link:https://codeforces.com/contest/1208/problem/D
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
#define TP pair<PI,int>
#define ff first
#define ss second
#define ft ff.ff
#define st ff.ss
#define MAX 211111
#define MOD 998244353
#define INF INT_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef struct seg_node
{
    int val=1e16;
    int ind=0;
}sn;

sn tree[4*MAX];
int lazy[4*MAX];

sn merge(sn a,sn b)
{
    sn tmp;
    if(a.val==b.val)
    {
        if(a.ind>=b.ind)
            tmp=a;
        else
            tmp=b;
    }
    else if(a.val<b.val)
        tmp=a;
    else
        tmp=b;
    return tmp;
}

void lazy_update(int x,int ss,int ee)
{
    tree[x].val+=lazy[x];
    if(ss!=ee)
    {
        lazy[2*x]+=lazy[x];
        lazy[2*x+1]+=lazy[x];
    }
    lazy[x]=0;
}

void built(int x,int ss,int ee,int *a)
{
    if(ss==ee)
    {
        tree[x]={a[ss],ss};
        return;
    }
    int m=(ss+ee)/2;
    built(2*x,ss,m,a);
    built(2*x+1,m+1,ee,a);
    tree[x]=merge(tree[2*x],tree[2*x+1]);
}

void update(int x,int ss,int ee,int l,int r,int val)
{
    lazy_update(x,ss,ee);
    if(ss>r || ee<l || l>r)
        return;
    if(ss>=l && ee <=r)
    {
        lazy[x]+=val;
        lazy_update(x,ss,ee);
        return;
    }
    int m=(ss+ee)/2;
    update(2*x,ss,m,l,r,val);
    update(2*x+1,m+1,ee,l,r,val);
    tree[x]=merge(tree[2*x],tree[2*x+1]);
}

sn query(int x,int ss,int ee,int l,int r)
{
    lazy_update(x,ss,ee);
    if(ss>r || ee<l || l>r)
        return tree[0];
    if(ss>=l && ee<=r)
        return tree[x];
    int m=(ss+ee)/2;
    query(2*x,ss,m,l,r);
    query(2*x+1,m+1,ee,l,r);
    return merge(tree[2*x],tree[2*x+1]);
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int n;
    cin>>n;

    int s[n+1],ans[n+1];
    for(int i=1;i<=n;i++)cin>>s[i];

    built(1,1,n,s);
    for(int i=1;i<=n;i++)
    {
        sn tmp=query(1,1,n,1,n);
        //cout<<tmp.val<<" "<<tmp.ind<<endl;
        ans[tmp.ind]=i;
        update(1,1,n,tmp.ind,tmp.ind,1e16);
        update(1,1,n,tmp.ind+1,n,-i);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
