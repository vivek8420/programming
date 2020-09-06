/*
	author : viviek8420
	problem: find lis for of path 1 to u for all vertex.
	link: https://atcoder.jp/contests/abc165/tasks/abc165_f
*/

#include <bits/stdc++.h>
using namespace std;
#include "string"
#define int long long
#define pi pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(nullptr)
const int N = 2e5 + 1;

vector<int>g[N];
int ans[N],a[N];
int n;
vector<int>ve;

void dfs(int u,int p){
	int del = -1;
	int pos = lower_bound(ve.begin(),ve.end(),a[u]) - ve.begin();
	if(pos != ve.size()){
		del = ve[pos];
		ve[pos] = a[u];
	}
	else
		ve.push_back(a[u]);
	ans[u] = ve.size();
	for(int v:g[u]){
		if(v==p)
			continue;
		dfs(v,u);
	}
	if(del == -1)
		ve.pop_back();
	else{
		pos = lower_bound(ve.begin(),ve.end(),a[u]) - ve.begin();
		ve[pos] = del;
	}
}


int32_t main(){ 
    boost;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1,u,v;i<n;i++){
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    	cout<<ans[i]<<endl;
}
