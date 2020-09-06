/*
    author:vivek8420
    problem:GSS3 - Can you answer these queries III(SPOJ)
    link:https://www.spoj.com/problems/GSS3/
    tag:segment_tree
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1111111

typedef struct seg_tree_node
{
    int ans,tot;
    int left,right;

    bool operator ==(seg_tree_node const &a)
    {
        if(ans==a.ans and left==a.left and right==a.right)
            return true;
        return false;
    }
}stn;

stn tree[4*MAX];
stn merge(stn p,stn q)
{
    stn tmp={0,0,0,0};
    if(p==tmp)
        return q;
    else if(q==tmp)
        return p;

    tmp.tot=p.tot+q.tot;
    tmp.ans=tmp.tot;
    tmp.ans=max(tmp.ans,q.ans);
    tmp.ans=max(tmp.ans,p.ans);
    tmp.ans=max(tmp.ans,p.right+q.left);

    tmp.left=p.left;
    tmp.left=max(tmp.left,p.tot+q.left);
    //tmp.left=max(tmp.left,p.tot+q.tot);

    tmp.right=q.right;
    tmp.right=max(q.tot+p.right,tmp.right);
    //tmp.right=max(q.tot+p.tot,tmp.right);
    return tmp;
}

void built(int x,int ss,int ee,int a[])
{
    if(ss==ee)
    {
        tree[x]={a[ss],a[ss],a[ss],a[ss]};
        return;
    }
    int mid=(ss+ee)/2;
    built(2*x,ss,mid,a);
    built(2*x+1,mid+1,ee,a);
    tree[x]=merge(tree[2*x],tree[2*x+1]);
}

void update(int x,int ss,int ee,int pos,int val)
{
    if(ss>pos || ee<pos)
        return;
    if(ss==ee)
    {
        tree[x]={val,val,val,val};
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
        return {0,0,0,0};
    if(ss>=l && ee<=r)
        return tree[x];
    int mid=(ss+ee)/2;
    stn p=query(2*x,ss,mid,l,r);
    stn q=query(2*x+1,mid+1,ee,l,r);
    return merge(p,q);
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q;
    cin>>n;
    int a[n+1]={0}
    ;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>q;
    built(1,1,n,a);
    while(q--)
    {
        int type,l,r;
        cin>>type>>l>>r;
        if(type==0)
            update(1,1,n,l,r);
        else
        {
            stn ans=query(1,1,n,l,r);
            cout<<ans.ans<<endl;
        }
    }   
}