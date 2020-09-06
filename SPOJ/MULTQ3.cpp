/*
*	author:vivek8420
*	problem:MULTQ3 - Multiples of 3
*	link:https://www.spoj.com/problems/MULTQ3/
*	tags:segment tree,lazy propogation
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
	int c0=0;
	int c1=0;
	int c2=0;

	seg_node operator+(const seg_node &a)
	{
		seg_node tmp;
		tmp.c0=a.c0+c0;
		tmp.c1=a.c1+c1;
		tmp.c2=a.c2+c2;
		return tmp;
	}
}sn; 

sn tree[4*MAX];
int lazy[4*MAX];

sn merge(sn a,sn b)
{
	sn tmp=a+b;
	return tmp;
}

void lazy_update(int x,int ss,int ee)
{
	lazy[x]%=3;
	if(lazy[x]==1)
	{
		sn tmp=tree[x];
		tree[x]={tmp.c2,tmp.c0,tmp.c1};
	}
	else if(lazy[x]==2)
	{
		sn tmp=tree[x];
		tree[x]={tmp.c1,tmp.c2,tmp.c0};
	}
	if(ss!=ee)
	{
		lazy[2*x]+=lazy[x];
		lazy[2*x+1]+=lazy[x];
	}
	lazy[x]=0;
}

void built(int x,int ss,int ee)
{
	if(ss==ee)
	{
		tree[x]={1,0,0};
		return;
	}
	int m=(ss+ee)/2;
	built(2*x,ss,m);
	built(2*x+1,m+1,ee);
	tree[x]=merge(tree[2*x],tree[2*x+1]);
}

void update(int x,int ss,int ee,int l,int r,int val)
{
	lazy_update(x,ss,ee);
	if(ss>r || ee<l || l>r)
		return;
	if(ss>=l && ee<=r)
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
		return {0,0,0};
	if(ss>=l && ee<=r)
		return tree[x];
	int m=(ss+ee)/2;
	sn p=query(2*x,ss,m,l,r);
	sn q=query(2*x+1,m+1,ee,l,r);
	return merge(p,q);
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int n,q;
    cin>>n>>q;
    built(1,1,n);
	while(q--)
	{
		int type,l,r;
		cin>>type>>l>>r;
		if(type==0)
			update(1,1,n,l+1,r+1,1);
		else
		{
			sn ans=query(1,1,n,l+1,r+1);
			cout<<ans.c0<<endl;
		}
	}
}
