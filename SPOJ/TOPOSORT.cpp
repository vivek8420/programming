/*
*   author:vivek8420
*   problem:TOPOSORT - Topological Sorting
*   link:https://www.spoj.com/problems/TOPOSORT/
*   tags:topo_sort,kahn algorithm,graph,priotity_queue
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1111111

vector<vector<int>>g;
vector<int>tp,in;
int cnt=0;	
void kahn(int n)
{
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=1;i<=n;i++)
		if(in[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		tp.push_back(u);
		for(int v:g[u])
		{
			in[v]--;
			if(in[v]==0)
				q.push(v);
		}
		cnt++;
	}
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;
    while(t--)
    {
    	int n,m;
    	cin>>n>>m;
    	g.resize(n+1);
    	in.resize(n+1,0);
    	for(int i=0;i<m;i++)
    	{
    		int u,v;
    		cin>>u>>v;
    		g[u].push_back(v);
    		in[v]++;
    	}
    	kahn(n);
    	if(cnt!=n)
    	{
    		cout<<"Sandro fails."<<endl;
    		return 0;
    	}
    	for(int v:tp)
    		cout<<v<<" ";
    	cout<<endl;
    }
}