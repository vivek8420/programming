#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define PI pair<int,int>
#define ff first
#define ss second

vector<vector<PI> >g;
int cost[MAX][MAX];
int flow;

bool bfs(int s,int t,int *par,int n)
{
    queue<PI>q;
    bool visit[n+1];
    memset(visit,false,sizeof visit);
    q.push({s,INT_MAX});
    visit[s]=true;
    while(!q.empty())
    {
        PI p=q.front();
        q.pop();
        for(int i=0;i<g[p.ff].size();i++)
        {
            int v=g[p.ff][i].ff;
            int wei=g[p.ff][i].ss;
            if(!visit[v] && cost[p.ff][v]>0)
            {
                visit[v]=true;
                par[v]=p.ff;
                int tmp=min(p.ss,wei);
                q.push({v,tmp});
                if(v==t)
                {
                    flow=tmp;
                    return true;
                }
            }
        }
    }
    return false;
}

int ford_fulkarshan(int s,int t,int n)
{
    int ans=0,par[n+1];
    while(bfs(s,t,par,n))
    {
        ans+=flow;
        //cout<<flow<<endl;
        for(int i=t;i!=s;i=par[i])
        {
            //cout<<i<<" "<<par[i]<<endl;
            cost[i][par[i]]+=flow;
            cost[par[i]][i]-=flow;
        }
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",strout);
    #endif // ONLINE_JUDGE

    int n,m,s,t;
    cin>>n>>m>>s>>t;
    g.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        cost[u][v]=w;
    }
    int ans=ford_fulkarshan(s,t,n);
    cout<<ans<<endl;
}
