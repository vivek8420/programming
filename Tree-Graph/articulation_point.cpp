/*
*   author:vivek8420
*   problem:Submerging Islands(SPOJ)
*   link:https://www.spoj.com/problems/SUBMERGE/
*   articulation point
*/

vector< vector<int> >g;
vector<bool>visit;
vector<int>low;
vector<int>dfs_n;
set<int>ap;
int cnt=0,root;

void dfs(int u,int p=-1){
	visit[u]=true;
	dfs_n[u]=low[u]=cnt++;
	int child=0;
	for(int v:g[u]) {
		if(v==p)
			continue;
		if(!visit[v]) {
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			child++;
			if(low[v]>=dfs_n[u] && u!=root)
				ap.insert(u);
		}
		else
			low[u]=min(low[u],dfs_n[v]);
	}
	if(u==root && child>1)
		ap.insert(u);
}


void articulatio_point(int n) {
	cnt=0;
	visit.resize(n+1,false);
	low.resize(n+1,-1);
	dfs_n.resize(n+1,-1);
	for(int i=1;i<=n;i++){
		if(!visit[i]) {
			root =i;
			dfs(i);
		}
	}
}


void flush() {
	g.clear();
	visit.clear();
	low.clear();
	dfs_n.clear();
	ap.clear();
}

