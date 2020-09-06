/*
* segment_tree datastructure
* author: savaliya_vivek
* question: HackerEarth (reversing Elements)
*qeution link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures
                           /segment-trees/practice-problems/algorithm/reversing-segments-53046b15/
*/




#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

struct Node
{
    ll maxSufix;
    ll maxPrefix;
    ll totalSum;
    ll maxSub;
};
Node tree[11111111];
Node merge(Node left,Node right)
{
    Node tmp;
    tmp.maxPrefix=max(left.maxPrefix,left.totalSum+right.maxPrefix);
    tmp.maxSufix=max(right.maxSufix,right.totalSum+left.maxSufix);
    tmp.totalSum=left.totalSum+right.totalSum;
    tmp.maxSub=max(left.maxSub,max(right.maxSub,left.maxSufix+right.maxPrefix));
    return tmp;
}

void built(ll cur,ll start,ll end,ll a[])
{
    if(start==end)
    {
     tree[cur].maxSufix=a[start];
     tree[cur].maxPrefix=a[start];
     tree[cur].totalSum=a[start];
     tree[cur].maxSub=a[start];
     return;
    }
    int mid=(start+end)/2;

    built(2*cur,start,mid,a);
    built(2*cur+1,mid+1,end,a);
    tree[cur]=merge(tree[2*cur],tree[2*cur+1]);
}

Node query(ll cur,ll start,ll end,ll l,ll r)
{
     if(l>end || r<start)
       return tree[0];
    if(l<=start && r>=end)
        return tree[cur];

    ll mid=(start+end)/2;
   Node left= query(2*cur,start,mid,l,r);
   Node right=query(2*cur+1,mid+1,end,l,r);
   Node res=merge(left,right);
   return res;
}

int main()
{
    boost;
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
  tree[0]={0,0,0,0};
    built(1,1,n,a);
    /*for(int i=1;i<=9;i++)
    {
     cout<<tree[i].maxPrefix<<" "<<tree[i].maxSufix<<" "<<tree[i].totalSum<<" "<<tree[i].maxSub<<endl;
    }*/

    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll ans=0;
       Node o_l,l_r,r_n;
        o_l=query(1,1,n,1,l-1);
        l_r=query(1,1,n,l,r);
        r_n=query(1,1,n,r+1,n);
        ans=max(ans,o_l.maxSub);
        ans=max(ans,l_r.maxSub);
        ans=max(ans,r_n.maxSub);
        ans=max(ans,o_l.maxSufix+l_r.maxSufix);
        ans=max(ans,l_r.maxPrefix+r_n.maxPrefix);
        ans=max(ans,o_l.maxSufix+l_r.totalSum+r_n.maxPrefix);
        cout<<ans<<endl;
    }
}
