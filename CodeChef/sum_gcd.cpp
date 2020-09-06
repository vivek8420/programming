/*
*   author: savaliya_vivek
*   problem: Sum And Gcd
*   link : https://www.codechef.com/JUNE19B/problems/SUMAGCD
*   -- fing gcd of given range using segment tree
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 1111111
#define MOD 1000000007
#define all(a) a.begin(),a.end()
#define INF LONG_MAX
#define MINF LONG_MIN

ll mod(ll m)
{
    while(m<0)
        m+=MOD;
    return m%MOD;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

struct segment_tree
{
    ll tree[MAX];

    void init()
    {
        memset(tree,0,sizeof tree);
    }

    void built(int x,int ss,int ee,ll arr[])
    {
        if(ss==ee)
        {
            tree[x]=arr[ss];
            return;
        }
          int mid=(ss+ee)/2;
          built(2*x,ss,mid,arr);
          built(2*x+1,mid+1,ee,arr);
          tree[x]=gcd(tree[2*x+1],tree[2*x]);
    }

    ll query(int node, int start, int end, int l, int r)
    {
        if(start > end || start > r || end < l)
            return 0;
        if(start >= l && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        ll p1 = query(node*2, start, mid, l, r);
        ll p2 = query(node*2 + 1, mid + 1, end, l, r);
        return gcd(p1, p2);
    }


}st;

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n+1];
        map<ll,ll>mp;
        int k=0;
        for(int i=1;i<=n;i++)
        {
            ll tmp;
            cin>>tmp;
            if(mp[tmp]==0)
            {
                mp[tmp]=1;
                k++;
                a[k]=tmp;
            }
        }

        if(k==1)
        {
            cout<<2*a[1]<<endl;
            continue;
        }
        st.init();
        st.built(1,1,k,a);
        ll ans=MINF;
        for(int i=1;i<=k;i++)
        {
            ll tmp;
            if(i==1)
            {
                tmp=st.query(1,1,k,2,k);
            }
            else if(i==k)
            {
                tmp=st.query(1,1,k,1,k-1);
            }
            else
            {
               ll tmp1=st.query(1,1,k,1,i-1);
               ll tmp2=st.query(1,1,k,i+1,k);
               tmp=gcd(tmp1,tmp2);
            }
            ans=max(ans,tmp+a[i]);
            //cout<<tmp<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}


