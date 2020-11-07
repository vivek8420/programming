
const int lv = 21;
vector < vector < int > > g,sp;
vector < int > sz;

void dfs(int u, int p) {
	sp[u][0] = p;
	for(int i = 1;  i < lv; i++)
		sp[u][i] = sp[sp[u][i - 1]][i - 1];
	sz[u] = sz[p] + 1;
	for(int v : g[u]) {
		if(v == p)
			continue;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if(sz[u] < sz[v])
		swap(u, v);
	int diff = sz[u] - sz[v];
	for(int i = 0; i < lv; i++) {
		if(diff & (1 << i))
			u = sp[u][i];
	} 
	if(u == v)
		return u;
	for(int i = lv - 1; i >= 0; i--) {
		if(sp[u][i] != sp[v][i]) {
			u = sp[u][i];
			v = sp[v][i];
		}
	}
	return sp[u][0];
}

int dist(int u, int v) {
	return sz[u] + sz[v] - 2 * sz[lca(u, v)];
}
