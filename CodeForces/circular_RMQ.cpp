/*
*	author:vivek8420
*	problem:C. Circular RMQ
*	link:https://codeforces.com/contest/52/problem/C
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


int tree[4*MAX];
int lazy[4*MAX];

vector<int>a;
void lazy_update(int x,int ss,int ee)
{
	tree[x]+=lazy[x];
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
		tree[x]=a[ss];
		return;
	}
	int m=(ss+ee)/2;
	built(2*x,ss,m);
	built(2*x+1,m+1,ee);
	tree[x]=min(tree[2*x],tree[2*x+1]);
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
	tree[x]=min(tree[2*x],tree[2*x+1]);
}

int query(int x,int ss,int ee,int l,int r)
{
	lazy_update(x,ss,ee);
	if(ss>r || ee<l || l>r)
		return INF;
	if(ss>=l && ee<=r)
		return tree[x];
	int m=(ss+ee)/2;
	int p=query(2*x,ss,m,l,r);
	int q=query(2*x+1,m+1,ee,l,r);
	return min(p,q);
}

int32_t main()
{
	boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int n,q;
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    built(1,1,n);
	cin>>q;
	while(q--)
	{
		int l,r,val;
		cin>>l>>r;
		l++,r++;
		if(cin.peek()==' ')
		{
			cin>>val;
			if(l<=r)
				update(1,1,n,l,r,val);
			else{
				update(1,1,n,l,n,val);
				update(1,1,n,1,r,val);
			}
		}
		else
		{
			int ans=0;
			if(l<=r)
				ans=query(1,1,n,l,r);
			else
				ans=min(query(1,1,n,l,n),query(1,1,n,1,r));
			cout<<ans<<endl;
		}
	}
}
