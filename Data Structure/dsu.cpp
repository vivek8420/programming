class dsu {
private:
	vector < int > par;
public:
	dsu(int n) {
		par.resize(n + 1);
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
		par[u] = v;
		return u == v;
	}
};
