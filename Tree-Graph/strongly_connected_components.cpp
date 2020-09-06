/**
*    strongly connected components Kosaraju's algorithm
*    for directed graph
**/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 111111
#define MOD 1000000007

vector<int> graph[MAX],rgraph[MAX];
vector<int>stk;
bool  visit[MAX];
int scc[MAX],sizecomp[MAX],grp=0;

void add(int u,int v)
{
    graph[u].push_back(v);
    rgraph[v].push_back(u);
}

void dfs1(int u)
{
    visit[u]=true;
    for(int i=0;i<graph[u].size();i++)
        if(!visit[graph[u][i]])
            dfs1(graph[u][i]);
    stk.push_back(u);
}

void dfs2(int u ,int val)
{
    scc[u]=val;
    sizecomp[val]++;
    for(int i=0;i<rgraph[u].size();i++)
    {
        int v=rgraph[u][i];
        if(scc[v]!=-1)
            dfs2(v,val);
    }
}

void scc()
{
    memset(sizecomp,0,sizeof sizecomp);
    memset(scc,-1,sizeof scc);
    memset(visit,flase,sizeof visit);

    for(int i=1;i<=n;i++)
        if(!visit[i])
            dfs1(i);
    reverse(stk.begin(),stk.end());
    for(int i=0;i<stk.size();i++)
    {
        if(scc[stk[i]]==-1)
            dfs2(stk[i],++grp);
    }
}


int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

}

