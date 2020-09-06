/*
*   author:savaliya_vivek
*   problem:Chef and Subarray Queries(CodeChef)
*   link:https://www.codechef.com/problems/CSUBQ
*   segment tree
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 500005
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef struct seg_tree_node
{
    int ans=0;
    int len=0,left=0,right=0;
}stn;


struct segment_tree
{
    stn tree[4*MAX];
    stn merge(stn p,stn q)
    {
        stn tmp;
        tmp.len=p.len+q.len;
        tmp.ans=p.ans+q.ans+p.right*q.left;

        tmp.left=p.left;
        if(p.len==p.left)
            tmp.left+=q.left;

        tmp.right=q.right;
        if(q.len==q.right)
            tmp.right+=p.right;
        return tmp;
    }

    stn leaf(int val)
    {
        stn tmp;
        tmp.ans=val;
        tmp.left=val;
        tmp.right=val;
        tmp.len=1;
        return tmp;
    }

    void built(int x,int ss,int ee)
    {
        if(ss==ee)
        {
            tree[x]=leaf(1);
            return;
        }
        int mid=(ss+ee)/2;
        built(2*x,ss,mid);
        built(2*x+1,mid+1,ee);
        tree[x]=merge(tree[2*x],tree[2*x+1]);
    }

    void update(int x,int ss,int ee,int pos,int val)
    {
        if(ss>pos || ee<pos)
            return;
        if(ss==ee)
        {
            tree[x]=leaf(val);
            return;
        }
        int mid=(ss+ee)/2;
        update(2*x,ss,mid,pos,val);
        update(2*x+1,mid+1,ee,pos,val);
        tree[x]=merge(tree[2*x],tree[2*x+1]);
    }

    stn query(int x,int ss,int ee,int l,int r)
    {
        if(ss>r || ee<l || r<l)
            return tree[0];
        if(ss>=l && ee<=r)
            return tree[x];
        int mid=(ss+ee)/2;
        stn p=query(2*x,ss,mid,l,r);
        stn q=query(2*x+1,mid+1,ee,l,r);
        return merge(p,q);
    }
};

int32_t main()
{
    boost;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q,L,R;
    cin>>n>>q>>L>>R;
    int a[n+1]={0};

    segment_tree s1,s2;
    s1.built(1,1,n);
    s2.built(1,1,n);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x,y;
            cin>>x>>y;
            if(y<L)
                s1.update(1,1,n,x,1);
            else
                s1.update(1,1,n,x,0);
            if(y<=R)
                s2.update(1,1,n,x,1);
            else
                s2.update(1,1,n,x,0);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            int ans=s2.query(1,1,n,l,r).ans-s1.query(1,1,n,l,r).ans;
            cout<<ans<<endl;
        }
    }   
}