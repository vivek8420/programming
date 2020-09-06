const int inf=1e15;
vector < vector<PI> > g;

vector<int> dijkstra(int sr,int n){
	bool visit[n+1];
	memset(visit,false,sizeof visit);
	vector<int>dist(n+1,inf);
	multiset<PI>ms;
	ms.insert({0,sr});
	dist[sr]=0;
	while(!ms.empty()){
		PI u=*ms.begin();
		ms.erase(u);
		if(visit[u.ss])
			continue;
		visit[u.ss]=true;
		for(PI v:g[u.ss]){
			if(!visit[v.ff] && dist[v.ff] >= u.ff+v.ss){
				dist[v.ff]=u.ff+v.ss;
				ms.insert({dist[v.ff],v.ff});
			}
		}
	}
	return dist;
}
