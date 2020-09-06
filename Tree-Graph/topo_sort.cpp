#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define PI pair<int,int>
#define MIN LONG_MIN
#define MAX LONG_MAX

vector<ll>graph[1111111],ts;

/*void topo_sort(int n)   // topological sorting using kahn's algorithm
{
         int in_degree[n+1];
         memset(in_degree,0,sizeof in_degree);

         for(int i=1;i<=n;i++)
         {
           for(int v=0;v<graph[i].size();v++)
             in_degree[graph[i][v]]++;
         }
          queue<int>qe;
          for(int i=1;i<=n;i++)
            if(in_degree[i]==0)
              qe.push(i);

           while(!qe.empty())
           {
                  int u=qe.front();
                  qe.pop();
                  ts.push_back(u);
                  for(int v=0;v<graph[u].size();v++)
                  {
                           in_degree[graph[u][v]]--;
                           if(in_degree[graph[u][v]]==0)
                            qe.push(graph[u][v]);
                  }
           }
}
*/
bool visit[1111111];
void topo_sort(int u)   // topological sorting using dfs
{
         visit[u]=true;
         for(int v=0;v<graph[u].size();v++)
         {
            if(!visit[graph[u][v]])
             topo_sort(graph[u][v]);
         }
         ts.push_back(u);
}
int main()
{
         boost;
         int n,m,a,b,p,q;
         cin>>n>>m;
         cin>>p>>q;
         for(int i=0;i<m;i++)
         {
                  cin>>a>>b;
                  graph[a].push_back(b);
         }
         memset(visit,false,sizeof visit);
         topo_sort(p);
         ll dp[n+1];
         fill(dp,dp+n+1,0);
         dp[q]=1;
         //reverse(ts.begin(),ts.end());
         for(int i=0;i<ts.size();i++)
         {
                 // cout<<ts[i]<<" ";
                  for(int v=0;v<graph[ts[i]].size();v++)
                     dp[ts[i]]=(dp[ts[i]]+dp[graph[ts[i]][v]])%MOD;
         }
         cout<<dp[p]<<endl;
}
