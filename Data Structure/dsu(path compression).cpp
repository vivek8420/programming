class dsu {
private:
	vector < int > par, sz;
public:
	dsu(int n) {
		par.resize(n + 1);
		sz.resize(n + 1, 1);
		iota(par.begin() , par.end() , 0);
	}

	int find(int u ) {
		if(par[u] == u)
			return u;
		return par[u] = find(par[u]);
	}

	bool Union(int u, int v) {
		u = find(u);
		v = find(v);
		if(u == v)
			return false;
		if(sz[u] > sz[v]) {
			par[v] = u;
			sz[u] += sz[v];
		}
		else {
			par[u] = v;
			sz[v] += sz[u];
		}
		return true;
	}
};
