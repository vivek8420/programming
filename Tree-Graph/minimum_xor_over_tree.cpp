
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<ll,ll>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 1111111

vector<ll>tree[MAX];
ll a[MAX],in[MAX],out[MAX],preoder[MAX],cnt;

void flush()
{
    for(int i=0;i<MAX;i++)
        tree[i].clear();
    memset(a,0,sizeof a);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
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

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int t;
    cin>>t;
    while(t--)
    {
        flush();
        ll n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs(1,0);
        ll ans1=0,ans2=0;
        while(q--)
        {
            ll v,k;
            cin>>v>>k;
            v=v^ans1;
            k=k^ans2;
            ll l=in[v],r=out[v];
            ans1=v;
            ans2=a[v]^k;
            for(int i=l;i<=r;i++)
            {
                ll tmp=a[preoder[i]]^k;
                if(tmp>ans2)
                {
                    ans2=tmp;
                    ans1=preoder[i];
                }
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
    }
}



