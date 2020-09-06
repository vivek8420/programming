/*
*	author:vivek8420
*	problem:A. Cutting Figure(CodeForces)
*	link:https://codeforces.com/contest/193/problem/A
*	tag:articulation_point,graph_thery,dfs,medium
*/


#include <bits/stdc++.h>
using namespace std;
#define PI pair<int,int>
#define TP pair<PI,int>
#define ff first
#define ss second
#define ft ff.ff
#define st ff.ss
#define MAX 1111111
#define MOD 998244353
#define INF INT_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

vector< vector<int>>g;
vector<int>low,tin;
vector<int>visit;
set<int>ap;
int cnt=0,root;

void dfs(int u,int p=-1)
{
	visit[u]=true;
	low[u]=tin[u]=cnt++;
	int child=0;
	for(int v:g[u])
	{
		if(v==p)
			continue;
		if(visit[v])
			low[u]=min(low[u],tin[v]);
		else
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			child++;
			if(u!=root && low[v]>=tin[u])
				ap.insert(u);
		}
	}
	if(u==root && child>1)
		ap.insert(u);
}

void articulatio_point(int n)
{
	visit.resize(n+1,false);
	tin.resize(n+1,-1);
	low.resize(n+1,-1);
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			root=i;
			dfs(i);
		}
	}
}

void add(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m;
    cin>>n>>m;
    
    string s[n];
    int num[n][m],c=0;
    for(int i=0;i<n;i++)
    {
    	cin>>s[i];
    	for(int j=0;j<m;j++)
    	{
    		if(s[i][j]=='#')
    			num[i][j]=++c;
    	}
    }

    if(c<3)
    {
    	cout<<-1<<endl;
    	return 0;
    }
    g.resize(c+1);

    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(s[i][j]=='#')
    		{
    			if(i>0 && s[i-1][j]=='#')
    				add(num[i][j],num[i-1][j]);
    			if(i+1<n && s[i+1][j]=='#')
    				add(num[i][j],num[i+1][j]);
    			if(j>0 && s[i][j-1]=='#'){
    				add(num[i][j],num[i][j-1]);
    			}
    			if(j+1<m && s[i][j+1]=='#'){
    				add(num[i][j],num[i][j+1]);
    			}
    		}
    	}
    }
    articulatio_point(c);
    if(ap.size()==0)
    	cout<<2<<endl;
    else
    	cout<<1<<endl;
}
