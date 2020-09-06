#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define PI pair<ll,ll>
#define _MIN LONG_MIN
#define _MAX LONG_MAX
vector<vector<PI>>graph;
vector<ll>dist;
vector<ll>pdist;
bool visit[22222];

void dijkstra(int n)
{
   vector<ll>last(n+1,_MAX);
   memset(visit,false,sizeof visit);
   dist=vector<ll>(n+1,_MAX);
   multiset<PI>ms;
   ms.insert({0,0});
   dist[0]=0;
   last[0]=0;
   while(!ms.empty())
   {
       PI p=*ms.begin();
       ms.erase(ms.begin());
       ll w=p.F;
       int x=p.S;

       if(visit[x])
        continue;
        visit[x]=true;

       for(int i=0;i<graph[x].size();i++)
       {
           ll wei=graph[x][i].F;
           int tmp=graph[x][i].S;
           if(!visit[tmp]&&(wei+w<dist[tmp] ||(wei+w==dist[tmp]&&wei<last[tmp])))
           {
               dist[tmp]=w+wei;
               last[tmp]=wei;
               ms.insert({dist[tmp],tmp});
           }
       }
   }
}

void prim(int n)
{
    memset(visit,false,sizeof visit);
    pdist=vector<ll>(n+1,_MAX);
    vector<ll>key(n+1,_MAX);
    multiset<PI>ms;
    ms.insert({0,0});
    pdist[0]=0;
    key[0]=0;
    while(!ms.empty())
    {
        PI p=*ms.begin();
        ms.erase(ms.begin());
        ll w=p.F;
        int x=p.S;
        visit[x]=true;
     for(int i=0;i<graph[x].size();i++)
     {
         ll wei=graph[x][i].F;
         int tmp=graph[x][i].S;
        if(visit[tmp]==false && key[tmp]>wei)
        {
         key[tmp]=wei;
          pdist[tmp]=w+wei;
          ms.insert({wei,tmp});
        }
      }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        graph.clear();
        int n,m;
        cin>>n>>m;
        graph.assign(n+1,vector<PI>());
        for(int i=0;i<m;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }
        dijkstra(n);
        prim(n);
        string ans="YES";
        for(int i=0;i<n;i++)
        {
             if(dist[i]!=pdist[i]||dist[i]==_MAX||pdist[i]==_MAX)
             {
                 ans="NO";
                 break;
             }
        }
        cout<<ans<<endl;
    }
}
