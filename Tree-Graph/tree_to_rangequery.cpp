#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<ll,ll>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 1111111

vector<int>tree[MAX];
int a[MAX],in[MAX],out[MAX],preoder[MAX],BIT[MAX],cnt;

void flush()
{
    for(int i=0;i<MAX;i++)
        tree[i].clear();
    memset(a,0,sizeof a);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    memset(BIT,0,sizeof BIT);
    memset(preoder,0,sizeof preoder);
    cnt=0;
}


void dfs(int u,int p)
{
    in[u]=++cnt;
    preoder[cnt]=u;
    for(int i=0;i<tree[u].size();i++)
    {
        ll v=tree[u][i];
        if(v!=p)
            dfs(v,u);
    }
    out[u]=cnt;
}

void update(int i,int x,int n)
{
    while(i<=n)
    {
        BIT[i]+=x;
        i+=i &(-i);
    }
}

int query(int i)
{
    int ans=0;
    while(i>0)
    {
        ans += BIT[i];
		i = i - (i & (-i));
    }
    return ans;
}

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int n,q;
    cin>>n>>q;

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0);

    for(int i=1;i<=n;i++)
    {
        if(a[preoder[i]]==0)
            update(in[preoder[i]],1,out[preoder[i]]);
    }

    while(q--)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            int x,l,r,ans=0;
            cin>>x;
            l=in[x];r=out[x];
            ans=query(r)-query(l-1);
             cout<<ans<<endl;
        }
        else
        {
            int v,x;
            cin>>v>>x;
            if(a[v]==0)
                update(in[v],-1,out[v]);
            a[v]+=x;
            if(a[v]==0)
             update(in[v],1,out[v]);
        }
    }
}

