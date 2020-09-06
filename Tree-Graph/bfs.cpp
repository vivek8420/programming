
vector<int> bfs(int x,int n){
	int visit[n+1]={0};
	vector<int>d(n+1,-1);
	queue<int>q;
	q.push(x);
	d[x]=0;
	visit[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(!visit[v]){
				d[v]=d[u]+1;
				q.push(v);
				visit[v]=1;
			}
		}
	}
	return d;
}
