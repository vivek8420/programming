

vector<int> dijkstra(int src) {
	vector <int > dp(n + 1, inf);
	dp[src] = 0;
	set < array < int, 2 > > st;
	st.insert({0, src});
	while(!st.empty()) {
		auto x = *st.begin();
		st.erase(x);
		for(auto &v : g[x[1]]) {
			if(dp[v.ff] > x[0] + v.ss) {
				dp[v.ff] = x[0] + v.ss;
				st.insert({x[0] + v.ss, v.ff});
			}
		}
	}
	return dp;
}
