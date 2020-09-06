/**
*   2-SAT algorithm
*   problem:E. The Road to Berland is Paved With Good Intentions(CodeForces)
*   link:https://codeforces.com/contest/228/problem/E
**/

//2-SAT from ashisgupta solution
// https://codeforces.com/contest/228/submission/39775751
struct Two_Satisfiability
{
	vector<int>graph[N],rgraph[N];
	bool visit[N];
	int scc[N],order[N]; // SCC stote strongly connected component
	int n,cnt;

	void init(int cur)
	{
		n=cur;
		cnt=1;
		for(int i=0;i<=n;i++)
		{
			graph[i].clear();
			rgraph[i].clear();
		}
		memset(visit,false,sizeof visit);
		memset(scc,-1,sizeof scc);
		memset(order,0,sizeof order);
	}

	void add(int u,int v)
	{
		graph[u].push_back(v);
		rgraph[u].push_back(v);
	}

	void dfs1(int u)
	{
		visit[u]=true;
		for(int i=0;i<graph[u].size();i++)
		{
			int v=graph[u][i];
			if(!visit[v])
				dfs1(v);
		}
		order[cnt++]=u;
	}

	void dfs2(int u,int c)
	{
			scc[u]=c;
			for(int i=0;i<rgraph[u].size();i++)
			{
				int v=graph[u][i];
				if(scc[v]==-1)
					dfs2(v,c);
			}
	}

	int solve(vector<int> &ans)
	{
		for(int i=1;i<=n;i++)
			if(!visit[i])
				dfs1(i);
		int grp=0;
		for(int i=n;i>0;i--)
		{
			int u=order[i];
			if(scc[u]==-1)
				dfs2(u,grp++);
		}

		for(int i=1;i<=n;i+=2)  // check  for any 2 vairable x and -x lie in  same SCC
			if(scc[i]==scc[i^1])
				return 0;
		for(int i=1;i<=n;i++)
		{
			int tmp= scc[i]>scc[i^1] ? i:(i^1);
			ans.push_back(tmp);
		}
		return 1;
	}

}TSAT;

void addEdge(int u,int v,int f) {
	int u0=2*(u-1), u1=2*(u-1) + 1; //0 = Unchanged, 1 = Changed
	int v0=2*(v-1), v1=2*(v-1) + 1; //0 = Unchanged, 1 = Changed
	if(f==0) {
		TSAT.add(u0, v1);
		TSAT.add(u1, v0);
		TSAT.add(v1, u0);
		TSAT.add(v0, u1);
	}
	else {
		TSAT.add(u0, v0);
		TSAT.add(u1, v1);
		TSAT.add(v0, u0);
		TSAT.add(v1, u1);
	}
}

int32_t main() {
	boost;
	int n,m;
	cin>>n>>m;
	TSAT.init(2*n);
	for(int i=1;i<=m;i++)
	{
		int u,v,k;
		cin>>u>>v>>k;
		addEdge(u,v,k);
	}
	vector<int>ans;

	if(TSAT.solve(ans))
	{
		int tmp=0;
		for(int i=0;i<ans.size();i++)
			tmp+=(ans[i]%2);
		cout<<tmp<<endl;
		for(int i=0;i<ans.size();i++)
			if(ans[i]%2)
				cout<<(ans[i]-1)/2 + 1<<" ";
		cout<<endl;
	}
	else
		cout<<"Impossible"<<endl;
}


