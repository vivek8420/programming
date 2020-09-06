/**
*   merge-sort tree
*   persistance segment tree
*   author:vivek8420
*   problem:MKTHNUM(SPOJ)
*   link:https://www.spoj.com/problems/MKTHNUM/
**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define PI pair<int,int>
#define MOD 1000000007
#define MAX 400005
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<int>ve;

struct merge_sort_tree
{
    vector<int>tree[MAX];
    void built(int x,int ss,int ee,int arr[])
    {
        if(ss==ee)
        {
            tree[x].push_back(arr[ss]);
            return;
        }
          int mid=(ss+ee)/2;
          built(2*x,ss,mid,arr);
          built(2*x+1,mid+1,ee,arr);
          merge(tree[2*x].begin(),tree[2*x].end(),tree[2*x+1].begin(),tree[2*x+1].end(),back_inserter(tree[x]));
    }

    int query(int node,int ss,int ee,int l,int r,int val)
    {
        if(ss>r || ee<l)
            return 0;
        if(ss>=l && ee<=r)
        {
            int tmp=upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
            return tmp;
        }
        int m=(ss+ee)/2;
        int p=query(2*node,ss,m,l,r,val);
        int q=query(2*node+1,m+1,ee,l,r,val);
        return p+q;
    }

    void flush()
    {
        for(int i=0;i<MAX;i++)
            tree[i].clear();
    }
}mst;

struct persistance_segment_tree
{
    int sz=0;
    int root[MAX];
    struct Node
    {
        int l,r,cnt;
    }node[MAX*20];

    void update(int &x,int pre,int ss,int ee,int pos)
    {
        x= ++sz;
        node[x] = node[pre];
        if(ss==ee && ss== pos) {
            node[x].cnt ++;
            node[x].l = node[x].r = 0;
            return;
        }
        int mid = (ss+ee)/2;
        if(pos<= mid)
            update(node[x].l, node[pre].l, ss, mid,pos);
        else
            update(node[x].r, node[pre].r, mid+1,ee,pos);
        node[x].cnt = node[node[x].l].cnt + node[node[x].r].cnt;
    }

    int query(int r1,int r2, int ss,int ee,int k)
    {
        if(ss==ee)
            return ss;
        int tmp = node[node[r1].l].cnt - node[node[r2].l].cnt;
        int mid = (ss+ee)/2;
        if(tmp >= k)
            return query(node[r1].l, node[r2].l,ss, mid,k);
        else
            return query(node[r1].r , node[r2].r, mid+1,ee,k -tmp);
    }

    void flush()
    {
        sz=0;
        memset(root,0,sizeof root);

        for(int i=0;i<20*MAX;i++)
            node[i].l=node[i].r=node[i].cnt=0;
    }
}pst;

void solve_pst(int q,int n,int a[])
{
    pst.update(pst.root[1], 0, 1, n,a[1]); // 0 -> is the initial empty segment tree
    for(int i = 2; i <= n; i ++ )
        pst.update(pst.root[i],pst.root[i-1],1,n,a[i]);

    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int ans=pst.query(pst.root[r],pst.root[l-1],1,n,k);
        cout<<ve[ans-1]<<endl;
    }
}

void solve_mst(int q,int n,int a[])
{
    mst.built(1,1,n,a);

    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int low = 1, high = n , mid, ans ;
        while(low <= high) {
            mid = (low + high) >> 1;
            int tmp= mst.query(1,1,n,l,r,mid);
            if(tmp >= k) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        cout<<ve[ans-1]<<endl;
    }
}
int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ve.push_back(a[i]);
    }
    sort(ve.begin(),ve.end());
    for(int i=1;i<=n;i++)                // strore index of a[i] in a[i]
        a[i]=lower_bound(ve.begin(),ve.end(),a[i])-ve.begin()+1;
    //solve_mst(m,n,a);
    solve_pst(m,n,a);
}
