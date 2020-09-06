/*
* segment_tree with lazy prapogation
* author: savaliya_vivek
* question: codechef(Addition and Multiplication--ADDMUL)
* question_link: https://www.codechef.com/problems/ADDMUL
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

ll tree[4*MAX],lazy_set[4*MAX],lazy_add[4*MAX],lazy_mul[4*MAX];

void built(int x,int ss,int ee,int arr[])
{
    lazy_set[x]=0;
    lazy_add[x]=0;
    lazy_mul[x]=1;
    if(ss==ee)
    {
        tree[x]=(arr[ss])%MOD;
    }
    else
    {
      int mid=(ss+ee)/2;
      built(2*x,ss,mid,arr);
      built(2*x+1,mid+1,ee,arr);
      tree[x]=(tree[2*x+1]+tree[2*x])%MOD;
    }
    return;
}

void lazy_update(int node,int start,int end)
{
   if (lazy_set[node] != 0)
    {
		tree[node] = (lazy_set[node] * (end - start + 1)) % MOD;
		if (start != end)
        {
			lazy_set[2*node+1] = lazy_set[node];
			lazy_set[2*node] = lazy_set[node];
			lazy_mul[2*node+1] = 1;
			lazy_mul[2*node] = 1;
			lazy_add[2*node+1] = 0;
			lazy_add[2*node] = 0;
		}
		lazy_set[node] = 0;
	}

	if (lazy_mul[node] != 1)
    {
		tree[node] = (tree[node] * lazy_mul[node]) % MOD;
		if (start!= end)
        {
			lazy_mul[2*node] = (lazy_mul[2*node] * lazy_mul[node]) % MOD;
			lazy_mul[2*node+1] = (lazy_mul[2*node+1] * lazy_mul[node]) % MOD;
			lazy_add[2*node+1] = (lazy_add[2*node+1]* lazy_mul[node]) % MOD;
			lazy_add[2*node] = (lazy_add[2*node] * lazy_mul[node]) % MOD;
		}
		lazy_mul[node]=1;
	}

	if (lazy_add[node] != 0)
    {
		tree[node] = (tree[node] + lazy_add[node]* (end -start + 1)) % MOD;
		if (end != start)
        {
			lazy_add[2*node+1] = (lazy_add[2*node+1]+ lazy_add[node]) % MOD;
			lazy_add[2*node] = (lazy_add[2*node] + lazy_add[node]) % MOD;
		}
		lazy_add[node]=0;
	}
}


void update(int node,int start, int end, int l, int r,int val,int type)
{
    lazy_update(node,start,end);
    if(start > end || start > r || end < l)
        return;
    if(start >= l && end <= r)
    {
        if(type==1)
            lazy_add[node]=val;
        else if(type==2)
            lazy_mul[node]=val;
        else if(type==3)
            lazy_set[node]=val;
        lazy_update(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, l, r, val,type);
    update(node*2 + 1, mid + 1, end, l, r, val,type);
    tree[node] = (tree[node*2] + tree[node*2+1])%MOD;
}

ll query(int node, int start, int end, int l, int r)
{
    lazy_update(node,start,end);
    if(start > end || start > r || end < l)
        return 0;
    if(start >= l && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    ll p1 = query(node*2, start, mid, l, r);
    ll p2 = query(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2)%MOD;
}


int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int n,q;
    cin>>n>>q;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(tree,-1,sizeof tree);
    built(1,1,n,a);
    while(q--)
    {
        /*for(int i=1;i<=7;i++)
            cout<<tree[i]<<" ";
        cout<<endl;
       */
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r,v;
            cin>>l>>r>>v;
            update(1,1,n,l,r,v,1);
        }
        else if(type==2)
        {
            int l,r,v;
            cin>>l>>r>>v;
            update(1,1,n,l,r,v,2);
        }
        else if(type==3)
        {
            int l,r,v;
            cin>>l>>r>>v;
            update(1,1,n,l,r,v,3);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            ll ans=query(1,1,n,l,r);
            cout<<ans<<endl;
        }
    }
}
