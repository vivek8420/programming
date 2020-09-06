#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 500005
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<vector<int>>g,rg,scc,ng;
stack<int>st;
vector<bool>visit;

void dfs(int u) {
	visit[u]=true;
	for(int v:g[u])
		if(!visit[v])
			dfs(v);
	st.push(u);
}

void dfs1(int u,vector<int>&ve) {
	visit[u]=true;
	ve.push_back(u);
	for(int v:rg[u]) {
		if(!visit[v])
			dfs1(v,ve);
	}
}

void kosaraju(int n) {
	visit.resize(n+1,false);
	for(int i=1;i<=n;i++) {
		if(!visit[i])
			dfs(i);
	}
	visit.clear();
	visit.resize(n+1,false);
	while(!st.empty()) {
		int u=st.top();
		st.pop();
		vector<int>ve;
		if(!visit[u]) {
			dfs1(u,ve);
			scc.push_back(ve);
		}
	}
}

/*create new graph take each scc as single node*/
void compress(int n,int m,int *a)
{
	ng.resize(m+1);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<scc[i].size();j++)
			a[scc[i][j]]=i+1;
	}
	map<pair<int,int>,int>mp;
	for(int i=0;i<g.size();i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			//cout<<a[i]<<" "<<a[g[i][j]]<<" "<<i<<" "<<g[i][j]<<endl;
			if(a[i]!=a[g[i][j]] && mp[{a[i],a[g[i][j]]}]==0)
			{
				ng[a[i]].push_back(a[g[i][j]]);
				mp[{a[i],a[g[i][j]]}]=1;
			}
		}
	}
}


int32_t main()
{
    boost;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    rg.resize(n+1);
    int c[n+1],a[n+1]={0};
    for(int i=1;i<=n;i++)
    	cin>>c[i];
    for(int i=0;i<m;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	g[u].push_back(v);
    	rg[v].push_back(u);
    }
   	kosaraju(n);
   	int sm=scc.size();
   	compress(n,sm,a);
}
