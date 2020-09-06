
const int inf=1e15;
vector < vector<PI> > g;

vector<int> bellman_ford(int sr,int n){
    vector<int>d(n+1, inf);
    d[sr] = 0;
    int x;
    for (int i=0; i<n; ++i){
        x = -1;
        for (int u=1; u<=n; ++u){
        	for(PI v:g[u]){
		        if (d[u]< inf){
		            if (d[v.ff] > d[u] + v.ss){
		                d[v.ff] = max (-inf, d[u] + v.ss);
		                x = v.ff;
		            }
		        }
         	}
        }
    }
    if(x==-1)
    	return d;
    else{
    	d[0]=-1;
    	return d;
    }
}

/* d[0]=-1 then negative cycle present
    else , d represent distance all node from source sr.
*/