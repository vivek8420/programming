/**
*   link: https://www.hackerearth.com/challenges/competitive/may-circuits-19/algorithm/repair-tree-339749d4/
*   problem: Repair this tree( MAY circuit)
**/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 1111111
#define MOD 1000000007
int par[MAX],in[MAX],out[MAX],cnt;
vector<int>tree[MAX];

void dfs(int u,int p)
{
    in[u]=++cnt;
    for(int i=0;i<tree[u].size();i++)
    {
        ll v=tree[u][i];
        if(v!=p)
            dfs(v,u);
    }
    out[u]=cnt;
}


int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n,q;
    cin>>n>>q;

    par[1]=1;
    for(int i=2;i<=n;i++)
    {
        cin>>par[i];
        tree[i].push_back(par[i]);
        tree[par[i]].push_back(i);
    }
    dfs(1,0);
    vector<PI>edge[MAX];
    int lans=0,m=0;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u=(u+lans-1)%n+1;
            v=(v+lans-1)%n+1;
            if(u!=v)
            {
              edge[w].push_back({u,v});
              m=max(m,w);
            }
        }
        else
        {
            int v,p;
            cin>>v>>p;
            v=(v+lans-1)%(n-1)+2;
            int sum=0,c=1,val=p;

            while(val<=m)
            {
                for(int i=0;i<edge[val].size();i++)
                {
                    int x =edge[val][i].ff;
                    int y =edge[val][i].ss;
                    int f=0;
                    if(in[x] >=in[v] && out[x]<=out[v])
                        f++;
                    if(in[y] >=in[v] && out[y]<=out[v])
                        f++;
                    if(f==1)
                        sum+=val;
                }
                c++;
                val=p*c;
            }
            lans=sum;
            cout<<sum<<endl;
        }
    }
}




