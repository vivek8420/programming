/*
	author:savaliya_vivek
	problem:Rootless Tree (ROOTLESS)
	link:https://www.codechef.com/problems/ROOTLESS
	-- lca of (u,v) with respect to root r
*/

#include<bits/stdc++.h>
using namespace std;
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 111111
#define MOD 1000000007
#define INF 9999999
#define lv 20

vector<vector<int>>tree;
int level[MAX],sparce[MAX][lv];

void dfs(int u,int p)
{
	level[u]=level[p]+1;
	sparce[u][0]=p;
	for(int v:tree[u]){
		if(v!=p)
			dfs(v,u);
	}
}

void sparce_table(int n)
{
	for(int j=1;j<lv;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(sparce[i][j-1]!=-1)
				sparce[i][j]=sparce[sparce[i][j-1]][j-1];
		}
	}
}

int lca(int u,int v)
{
	if(level[u]>level[v])
		swap(u,v);
	int d=level[v]-level[u];
	for(int i=0;i<lv;i++)
		if((d>>i)&1)
			v=sparce[v][i];
	if(v==u)
		return u;
	for(int i=lv-2;i>=0;i--)
	{
		if(sparce[u][i]!=sparce[v][i])
		{
			u=sparce[u][i];
			v=sparce[v][i];
		}
	}
	return sparce[u][0];
}

void built(int n)
{
	memset(level,0,sizeof level);
	memset(sparce,-1,sizeof sparce);
	dfs(1,0);
	sparce_table(n);
}

PI query(int u,int v,int r)
{
	int p=lca(u,v);
	int ua=level[u]-level[p];
	int va=level[v]-level[p];
	if(lca(p,r)!=p)
		return {ua,va};
	else if(lca(u,r)!=p)
	{
		int np =lca(u,r);
		int sl=level[np]-level[p];
		return {ua-sl,va+sl};
	}
	else if(lca(v,r)!=p)
	{
		int np=lca(v,r);
		int sl=level[np]-level[p];
		return{ua+sl,va-sl};
	}
	else
		return {ua,va};

}
int32_t main()
{
	boost;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	
	int n,q,u,v,r;
	cin>>n>>q;
	tree.resize(n+1); 	
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	built(n);
	
	while(q--)
	{
		cin>>r>>u>>v;
		PI p=query(u,v,r);
		cout<<p.ff<<" "<<p.ss<<endl;
	}
}
 