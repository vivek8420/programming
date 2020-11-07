/*
*   author:vivek8420
*   problem:EC_P - Critical Edges(SPOJ)
*   link:https://www.spoj.com/problems/EC_P/
*   tag:bridge,graph_thoery,dfs
*/

vector< vector < int > > g;
vector< int > low, dfs_n;
vector< bool > visit;
set< pair< int, int > > ans;
int cnt = 0;

void dfs(int u, int p = -1) {
	visit[u] = true;
	dfs_n[u] = low[u] = cnt++;
	for(int v : g[u] ) {
		if(v == p)
			continue;
		if(!visit[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfs_n[u])
				ans.insert({min(u, v), max(u, v)});
		}
		else
			low[u] = min(low[u], dfs_n[v]);
	}
}

void bridge(int n) {
	cnt = 0;
	low.assign(n + 1, -1);
	visit.assign(n + 1, false);
	dfs_n.assign(n + 1, -1);
	for(int i = 1; i <= n; i++)
		if(!visit[i])
			dfs(i);
}

void flush() {
	g.clear();
	low.clear();
	visit.clear();
	dfs_n.clear();
	ans.clear();
}


