/**
*    subtree sum using Euler Tour and segment tree
*    time=q*lon(n)
*    author:vivek8420
*    link:https://www.geeksforgeeks.org/euler-tour-subtree-sum-using-segment-tree/
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define PI pair<ll,ll>
#define MAX 111111
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<int>tree[MAX];
vector<int>euler;
bool visit[MAX];
int in[MAX],out[MAX],cnt=0;

void EulerTour(int x,int prev)
{
    in[x]=++cnt;
    euler.push_back(x);
    for(int i=0;i<tree[x].size();i++)
    {
        if(tree[x][i]!=prev)
            EulerTour(tree[x][i],x);
    }
    euler.push_back(x);
    out[x]=++cnt;
}

struct segment_tree
{
    ll stree[MAX];

    void built(int x,int ss,int ee,int arr[])
    {
        if(ss==ee)
        {
            stree[x]=arr[euler[ss-1]];
            return;
        }
          int mid=(ss+ee)/2;
          built(2*x,ss,mid,arr);
          built(2*x+1,mid+1,ee,arr);
          stree[x]=stree[2*x]+stree[2*x+1];
    }

    void update(int node,int ss,int ee,int pos,int val)
    {
        if(ss>pos || ee<pos)
            return;
        if(ss==ee)
        {
            stree[node]=val;
            return;
        }
        int m=(ss+ee)>>1;
        update(2*node,ss,m,pos,val);
        update(2*node+1,m+1,ee,pos,val);
        stree[node]=stree[2*node]+stree[2*node+1];
        return;
    }

    ll query(int node,int ss,int ee,int l,int r)
    {
        if(ss>r || ee<l)
            return 0;
        if(l<=ss && ee<=r)
            return stree[node];
        int m=(ss+ee)>>1;
        ll p1=query(2*node,ss,m,l,r);
        ll p2=query(2*node+1,m+1,ee,l,r);
        return (p1+p2);
    }
}SEGT;




int main()
{
     boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n,q;
    cin>>n>>q;
    int a[n+1];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        cin>>a[i];

    EulerTour(1,0);
    int len=euler.size();
    SEGT.built(1,1,len,a);

    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int u;
            cin>>u;
            ll ans=SEGT.query(1,1,len,in[u],out[u]);
            cout<<ans/2<<endl;
        }
        else
        {
            int u,val;
            cin>>u>>val;
            SEGT.update(1,1,len,in[u],val);
            SEGT.update(1,1,len,out[u],val);
        }
    }
}
