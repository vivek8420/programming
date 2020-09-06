/**
*   author:vivek8420
*   link:https://www.hackerearth.com/challenges/competitive/june-circuits-19/algorithm/an-interesting-partition-problem-june-circuits-18f83691/
*   time: n*log(n)*log(n)
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define TP pair<PI,int>
#define MAX 1111111
#define INF LONG_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007

struct segment_tree
{
    double tree[MAX];

    void built(int x,int ss,int ee,double arr[])
    {
        if(ss==ee)
        {
            tree[x]=arr[ss];
            return;
        }
          int mid=(ss+ee)/2;
          built(2*x,ss,mid,arr);
          built(2*x+1,mid+1,ee,arr);
          tree[x]=tree[2*x+1]+tree[2*x];
    }

    void update(int node,int ss,int ee,int pos,double val)
    {
        //cout<<pos<<" "<<val<<endl;
        if(ss>pos || ee<pos)
            return;
        if(ss==ee)
        {
            tree[node]+=val;
            return;
        }
        int m=(ss+ee)>>1;
        update(2*node,ss,m,pos,val);
        update(2*node+1,m+1,ee,pos,val);
        tree[node]=tree[2*node]+tree[2*node+1];
        return;
    }


    double query(int node, int start, int end, int l, int r)
    {
        if(start > end || start > r || end < l)
            return 0;
        if(start >= l && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        double p1 = query(node*2, start, mid, l, r);
        double p2 = query(node*2 + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

    void flush()
    {
        memset(tree,0,sizeof tree);
    }

}st;

double sum(double a[],ll ss,ll ee)
{
    double ans=0;
    for(int i=ss;i<=ee;i++)
        ans+=a[i];
    return ans;
}


double query(double a[],ll n)
{
    ll l=1,r=n,ans=1;
    double left=a[1];
    double right = st.query(1,1,n,2,n);
    double tmp=abs(left-right);
    while(l<=r)
    {
        ll m =(l+r)/2;
        //cout<<l<<" "<<r<<" "<<m<<endl;
        left=st.query(1,1,n,1,m);
        right=st.query(1,1,n,m+1,n);
       // cout<<left<<" "<<sum(a,1,m)<<endl;
        if(abs(left-right)<tmp)
        {
            tmp=abs(left-right);
            ans=m;
        }
        else if(abs(left-right)==tmp)
            ans=min(ans,m);
        if(left<right)
            l=m+1;
        else
            r=m-1;
    }
    return ans;
}

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    ll n,m;
    cin>>n>>m;
    double a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=log2(a[i]);
    }
    st.built(1,1,n,a);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            ll x,val;
            cin>>x>>val;
            double v=log2(val);
            a[x]+=v;
            st.update(1,1,n,x,v);
        }
        else
        {
            ll ans=query(a,n);
            cout<<ans<<endl;
        }
    }
}
