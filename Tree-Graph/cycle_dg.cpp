/*
	author : vivek8420
	problem:https://atcoder.jp/contests/abc142/tasks/abc142_f
	time : O(N*(N+M))
	find cycle on dg or min length cycle in dg(directed graph)
*/




#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pi pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(nullptr)
#include "string"

const int N = 1001;
const int inf = 1e9;
int g[N][N];
vector<int>adj[N];

void print(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
}

void bfs(int x){
	memset(g[x],1,sizeof g[x]);
	queue<int>q;
	q.push(x);
	g[x][x] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v:adj[u]){
			if(g[x][v]>g[x][u]){
				g[x][v] = g[x][u] + 1;
				q.push(v);
			}
		}
	}
}

int32_t main() { 
	boost;
	int n,m;
	cin>>n>>m;
	memset(g,1,sizeof g);
	for(int i=0,u,v;i<m;i++){
		cin>>u>>v;
		g[u][v] = 1;
		adj[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		bfs(i);
	//print(n);
	int root = 1,mx = g[0][0];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j)
				continue;
			if(g[i][j]+g[j][i] < mx){
				mx = g[i][j]+g[j][i];
				root = i;
			}
		}
	}

	if(mx == g[0][0]){
		cout<<-1<<endl;
		return 0;
	}

	cout<<mx<<endl;
	for(int i=1;i<=mx;i++){
		cout<<root<<endl;
		for(int v:adj[root]){
			if(g[v][root] + g[root][v] == mx){
				root = v;
				break;
			}
		}
	}
}
