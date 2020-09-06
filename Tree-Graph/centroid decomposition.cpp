/**
*   centroid decomposition
*   author: vivek8420
*   problem:codeforces
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 111111
#define MOD 1000000007
#define INF 9999999
#define lv 20
vector<int>tree[MAX];

struct lca_sparce_table
{
	bool visit[MAX];
	int sparce[MAX][lv],level[MAX];

	void dfs(int u,int prev)
	{
		level[u]=level[prev]+1;
		sparce[u][0]=prev;
		visit[u]=true;

		for(int i=0;i<tree[u].size();i++)
		{
			if(!visit[tree[u][i]])
			{
				dfs(tree[u][i],u);
			}
		}
	}

	void sparceTable(int n)
	{
		for(int i=1;i<lv;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(sparce[j][i-1]!=-1)
				{
					sparce[j][i]=sparce[sparce[j][i-1]][i-1];
				}
			}
		}
	}

	int lca(int u,int v)
	{
		if (level[v] < level[u])
			swap(u, v);
		int diff = level[v] - level[u];
		for (int i=0; i<lv; i++)
			if ((diff>>i)&1)
				v = sparce[v][i];
		if (u == v)
			return u;
		for (int i=lv-1; i>=0; i--)
			if (sparce[u][i] != sparce[v][i])
			{
				u = sparce[u][i];
				v = sparce[v][i];
			}
		return sparce[u][0];
	}

	int dist(int u,int v)
	{
		return level[u] + level[v] - 2*level[lca(u,v)];
	}


	void built(int n)
	{
		dfs(1,0);
		sparceTable(n);
	}

	void flush()
	{
		memset(visit,false,sizeof visit);
		memset(level,0,sizeof level);
		memset(sparce,-1,sizeof sparce);
		for(int i=0;i<MAX;i++)
			tree[i].clear();
	}
}LCA;



struct centroid_decomposition_tree
{
	int subsize[MAX],par[MAX],ans[MAX];
	int nv=0,n=0;
	set<int>stree[MAX];

	void dfs1(int u,int p)
	{
		nv++;
		subsize[u]=1;
		for(int v:stree[u])
		{
			if(v!=p)
			{
				dfs1(v,u);
				subsize[u]+=subsize[v];
			}
		}
	}

	int dfs2(int u,int p)
	{
		for(int v:stree[u])
		{
			if(v!=p && subsize[v]> nv/2)
				return dfs2(v,u);
		}
		return u;
	}

	void cd(int u,int p)
	{
		nv=0;
		dfs1(u,u);
		int centroid=dfs2(u,u);

		if(p!=-1)
		{
			par[centroid]=p;
			//cout<<centroid<<" "<<p<<endl;
		}

		for(int v:stree[centroid])
		{
			stree[v].erase(centroid);
			cd(v,centroid);
		}
		stree[centroid].clear();
	}

	void update(int u)
	{
		int x=u;
		while(1)
		{
			ans[x]=min(ans[x],LCA.dist(x,u));
			if(x==par[x])
				break;
			x=par[x];
		}
	}

	int query(int u)
	{
		int x=u;
		int res=INF;
		while(1)
		{
			res=min(res,LCA.dist(u,x)+ans[x]);
			if(x==par[x])
				break;
			x=par[x];
		}
		return res;
	}

	void built(int m)
	{
		n=m;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<tree[i].size();j++)
				stree[i].insert(tree[i][j]);
		}
		for(int i=0;i<=n;i++)
			ans[i]=INF;

		cd(1,-1);
	}

	void flush()
	{
		memset(subsize,0,sizeof subsize);
		memset(par,-1,sizeof par);
		nv=0;
		for(int i=0;i<MAX;i++)
			stree[i].clear();
	}
}CDT;


int main()
{
	boost;
	#ifndef ONLINE_JUDGE
	 freopen("input.c","r",stdin);
	 freopen("output.c","w",stdout);
	#endif // ONLINE_JUDGE

	int n,m;
	cin>>n>>m;

	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	LCA.built(n);
	CDT.built(n);
	CDT.update(1);  // First node initially red
	while(m--)
	{
		int type,u;
		cin>>type>>u;
		if(type==1)
			CDT.update(u);
		else
		{
			int ans=CDT.query(u);
			cout<<ans<<endl;
		}
	}
}
