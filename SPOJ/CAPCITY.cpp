/*
*   author:vivel8420
*   problem:CAPCITY - Capital City
*   link:https://www.spoj.com/problems/CAPCITY/
*   tag:scc,kosaraju,graph
*/



#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g,rg,ng,scc;
stack<int>st;
vector<int>visit;

void dfs(int u)
{
	visit[u]=true;
	for(int v:g[u])
		if(!visit[v])
			dfs(v);
	st.push(u);
}

void dfs1(int u,vector<int>&ve)
{
	visit[u]=true;
	ve.push_back(u);
	for(int v:rg[u])
	{
		if(!visit[v])
			dfs1(v,ve);
	}
}

void kosaraju(int n)
{
	visit.resize(n+1,0);
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
			dfs(i);
	}
	visit.clear();
	visit.resize(n+1,0);
	while(!st.empty())
	{
		int u=st.top();
		st.pop();
		vector<int>ve;
		if(!visit[u])
		{
			dfs1(u,ve);
			scc.push_back(ve);
		}
	}
}

void compress(int n,int m,int *a)
{
    for(int i=0;i<m;i++)
    {
        for(int v:scc[i])
            a[v]=i+1;
    }
    ng.resize(m+1);
    map<pair<int,int>,int>mp;
    for(int i=0;i<g.size();i++)
    {
        for(int v:g[i])
        {
            if(a[i]!=a[v] && mp[{a[i],a[v]}]==0)
            {
                ng[a[i]].push_back(a[v]);
                mp[{a[i],a[v]}]=1;
            }
        }
    }
}


int32_t main()
{
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    rg.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    
    kosaraju(n);
    /*for(int i=0;i<scc.size();i++)
    {
        for(int v:scc[i])
            cout<<v<<" ";
        cout<<endl;
    }*/
    int a[n+1]={0};
    int sm=scc.size();
    compress(n,sm,a);
    /*for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;*/
    int in[sm+1]={0},out[sm+1]={0},cnt=0,u=-1;
   	for(int i=0;i<ng.size();i++)
   	{
   		for(int v:ng[i])
   		{
   			in[v]++;
   			out[i]++;
   		}
   	}
   	
    int x=0,y=0,z=0;
    for(int i=1;i<=sm;i++)
    {
        if(out[i]==1)
            x++;
        else
        {
            y++;
            u=i;
        }
    }
    //cout<<sm<<" "<<x<<" "<<y<<endl;
    if(y==1 && x==sm-1)
    {
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==u)
                ans.push_back(i);
        }
        cout<<ans.size()<<endl;
        for(int v:ans)
            cout<<v<<" ";
        cout<<endl;    
    }
    else
        cout<<0<<endl;
}
