/*
    author:savaliya_vivek
    problem:Lowest Common Ancestor(TALCA)
    link:https://www.codechef.com/problems/TALCA
    tags:lac,sparce table,dfs,tree
*/

#include<bits/stdc++.h>
using namespace std;
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define lv 20

const int N = 1e5 + 5;
vector<vector<int>>tree;
int level[N],sparce[N][lv];

void dfs(int u,int p)
{
    level[u]=level[p]+1;
    sparce[u][0]=p;
    for(int v:tree[u]){
        if(v!=p)
            dfs(v,u);
    }
}

void sparce_table(int n)
{
    for(int j=1;j<lv;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(sparce[i][j-1]!=-1)
                sparce[i][j]=sparce[sparce[i][j-1]][j-1];
        }
    }
}

int lca(int u,int v)
{
    if(level[u]>level[v])
        swap(u,v);
    int d=level[v]-level[u];
    for(int i=0;i<lv;i++)
        if((d>>i)&1)
            v=sparce[v][i];
    if(v==u)
        return u;
    for(int i=lv-2;i>=0;i--)
    {
        if(sparce[u][i]!=sparce[v][i])
        {
            u=sparce[u][i];
            v=sparce[v][i];
        }
    }
    return sparce[u][0];
}

void built(int n)
{
    memset(level,0,sizeof level);
    memset(sparce,-1,sizeof sparce);
    dfs(1,0);
    sparce_table(n);
}

int query(int u,int v,int r)
{
    int p=lca(u,v);
    if(lca(p,r)!=p)
        return p;
    else if(lca(u,r)!=p)
        return lca(u,r);
    else if(lca(v,r)!=p)
        return lca(v,r);
    else
        return p;
}

int32_t main()
{
    boost;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n,q,u,v,r;
    cin>>n;
    tree.resize(n+1);   
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    built(n);
    cin>>q;
    while(q--)
    {
        cin>>r>>u>>v;
        int la=query(u,v,r);
        cout<<la<<endl;
    }
}
 