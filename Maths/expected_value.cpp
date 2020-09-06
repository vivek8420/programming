/*
    author: savaliya_vivek
    problem:Expected Product (CodeChef)
    link :https://www.codechef.com/problems/EXPTPROD
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long
#define PI pair<int,int>
#define TP pair<PI,int>
#define ff first
#define ss second
#define fff ff.ff
#define fss ff.ss
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 1111
#define MOD 1000000007
#define INF INT_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()

ll mod(ll m)
{
    while(m<0)
        m+=MOD;
    return m%MOD;
}

ll power(ll x,ll y)
{
    ll res = 1;
    x = mod(x);
    while (y > 0)
    {
        if (y & 1)
            res =mod(res*x);
        y = y>>1;
        x = mod(x*x);
    }
    return mod(res);
}

ll modInverse(ll a) //extended euclid
{
    ll m=MOD;
    ll m0 =m;
    ll y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}

vector<int> mul(vector<int> a,vector<int> b,int n)
{
    vector<int>dummy(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int k=(i*j)%n;
            dummy[k]=mod(dummy[k] + mod(a[i]*b[j]));
            //cout<<i<<" "<<j<<" "<<k<<" "<<a[i]<<" "<<b[j]<<" "<<dummy[k]<<endl;
        }
    }
    return dummy;
}

vector<int> solve(vector<int> a,int k,int n)
{
    if(k==1)
        return a;
    vector<int> ve= solve(mul(a,a,n),k/2,n);
    if(k&1)
        ve=mul(ve,a,n);
    return ve;
}

int32_t main()
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
        int n,k;
        cin>>n>>k;
        vector<int>a(n,0);
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            a[tmp]++;
        }
        vector<int> res=solve(a,k,n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=mod(ans + mod(i*res[i]));
            //cout<<res[i]<<" ";
        }
        ans = mod(ans * modInverse(power(n,k)));
        cout<<ans<<endl;
    }
}
