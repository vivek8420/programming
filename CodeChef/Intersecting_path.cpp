/**
*   author: savaliya_vivek
*   problem: Intersecting Path
*   link:https://www.codechef.com/JUNE19B/problems/INTRPATH
*   time=O(nlogn)
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<ll,ll>
#define TP pair<PI,int>
#define ff first
#define ss second
#define ft ff.ff
#define st ff.ss
#define MAX 1111111
#define MOD 1000000007
#define INF INT_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define lv 20

vector<ll>tree[MAX];
vector<ll>euler,depthArr;
ll dp[MAX][lv],par[MAX];
ll sub[MAX],pre[MAX],ssub[MAX];
ll level[MAX],FAI[MAX],cnt,p2[50];
ll logn[MAX];

void flush()
{
       cnt=0;
        memset(level,-1,sizeof level);
        memset(dp,-1,sizeof dp);
        memset(par,0,sizeof par);
        memset(sub,0,sizeof sub);
        memset(pre,0,sizeof pre);
        memset(FAI,-1,sizeof FAI);
        memset(ssub,0,sizeof ssub);
        memset(p2,0,sizeof p2);
        for(int i=0;i<MAX;i++)
            tree[i].clear();
        euler.clear();
        depthArr.clear();
}

void buildSparseTable(int n)
{
    memset(dp,-1,sizeof(dp));
    for (int i=1; i<n; i++)
        dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i;
    for (int l=1; l<lv; l++)
      for (int i=0; i<n; i++)
        if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1)
          dp[i][l] =
            (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])?
             dp[i+p2[l-1]][l-1] : dp[i][l-1];
        else
             break;
}

ll query(int l,int r)
{
    if(l>r)
        swap(l,r);
    int d = r-l;
    int dx = logn[d];
    if (l==r)
        return l;
    if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]])
        return dp[r-p2[dx]][dx];
    else
        return dp[l][dx];
}

void preprocess()
{
    p2[0] = 1;
    for (int i=1; i<50; i++)
        p2[i] = p2[i-1]*2;
    int val = 1,ptr=0;
    for (int i=1; i<MAX; i++)
    {
        logn[i] = ptr-1;
        if (val==i)
        {
            val*=2;
            logn[i] = ptr;
            ptr++;
        }
    }
}

void dfs(int u,int prev)
    {
        if(FAI[u]==-1)
            FAI[u]=cnt;
        cnt++;
        sub[u]=1;
        par[u]=prev;
        ssub[u]=0;
        level[u]=level[prev]+1;
        euler.push_back(u);
        for(int i=0;i<tree[u].size();i++)
        {
            int v=tree[u][i];
            if(v!=prev)
            {
                dfs(v,u);
                euler.push_back(u);
                sub[u]+=sub[v];
                ssub[u]+=sub[v]*sub[v];
                cnt++;
            }
        }
    }

void makeArr()
{
    for (int i=0;i<euler.size();i++)
        depthArr.push_back(level[euler[i]]);
}

int lca(int u,int v)
{
    if (FAI[u] > FAI[v])
       swap(u,v);
    int ans=query(FAI[u], FAI[v]);
    return ans;
}

void dfs1(int u,int p)
{
    pre[u]+=pre[p];
    if(u!=1)
    {
        //cout<<u<<" "<<pre[p]<<" "<<pre[u]<<endl;
        ll a=sub[p]-sub[u];
        pre[u]-=a*sub[u];
    }
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v!=p)
            dfs1(v,u);
    }
}

PI find_child(int u,int v,int la,int lc)
{
    if(u>v)
        swap(u,v);
    int cu=0,cv=0,tt;
    if(u!=la)
    {
        tt=query(u,la-1);
        while(euler[tt]==lc)
            tt=query(u,tt-1);
        cu=euler[tt];
    // cout<<tt<<" "<<cu<<endl;
    }
    if(v!=la)
    {
        tt=query(la+1,v);
        while(euler[tt]==lc)
            tt=query(tt+1,v);
        cv=euler[tt];
    }
    //cout<<tt<<" "<<cv<<endl;
    return {cu,cv};
}

void query1(int u,int v)
{
    if(u>v)
        swap(u,v);
    int tt = lca(u,v);
    //cout<<u<<" "<<v<<endl;
    int la = euler[tt];
    ll ans= pre[u] + pre[v]-pre[la];
    ll tmp=0;
    if(u!=la || v!=la)
    {
        PI c=find_child(FAI[u],FAI[v],tt,la);
      // cout<<la<<" "<<c.ff<<" "<<c.ss<<endl;
        ans+=sub[c.ff]*sub[c.ss];
        tmp=sub[c.ff]+sub[c.ss];
    }
    ll sum = sub[la]-tmp;
    //ans+=sum*tmp;
    //cout<<pre[u]<<" "<<pre[v]<<" "<<pre[la]<<endl;
    if(la != 1)
    {
        ans-=pre[par[la]];
        ll a=sub[1]-sub[la];
        ll b = sub[par[la]]-sub[la];
        ans+=b*sub[la];
        a=a*sum;
        ans+=a;
    }
    printf("%lld\n",ans);
}


void built()
{
    preprocess();
    dfs(1,0);
    makeArr();
    buildSparseTable(depthArr.size());
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q,u,v;
        scanf("%d %d",&n,&q);
        flush();
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        built();
        /*for(int i=0;i<euler.size();i++)
            cout<<euler[i]<<" ";
        cout<<endl;

        for(int i=0;i<depthArr.size();i++)
            cout<<depthArr[i]<<" ";
        cout<<endl;
        */
        for(int i=1;i<=n;i++)
        {
            pre[i]=((sub[i]-1)*(sub[i]-1) - ssub[i])/2 + sub[i];
        }
        //dfs(1,0);
        dfs1(1,0);

       /* for(int i=1;i<=n;i++)
            cout<<i<<" "<<sub[i]<<" "<<ssub[i]<<" "<<pre[i]<<" "<<pre2[u]<<" "<<par[i]<<endl;
            */
        while(q--)
        {
            scanf("%d %d",&u,&v);
            query1(u,v);
        }
    }
}

