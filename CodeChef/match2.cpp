/**
* suare root decomposition
* problem= Match The Stream(MATCH2) lunch time
* author:savaliya_vivek
**/

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007s
#define PI pair<ll,ll>
#define _MIN LONG_MIN
#define _MAX LONG_MAX

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int t;
    cin>>t;
while(t--)
{
    ll n,q;
    cin>>n>>q;
    ll a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    ll bl=sqrt(n),ans=0;
    ll bn= n%bl==0 ? n/bl:n/bl+1;

    unordered_map<ll,ll>mp[bn];
    ll count[bn],f[bn],val[bn];
    memset(count,0,sizeof count);
    memset(f,-1,sizeof f);
    memset(val,0,sizeof val);

    for(int i=0;i<n;i++)
    {
        ll bi=i/bl;
        mp[bi][b[i]]++;
        if(a[i]==b[i])
        {
            count[bi]++;
            ans++;
        }
    }
    while(q--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        x=x^ans;
        y=y^ans;
        z=z^ans;
        ll bt=(x-1)/bl;
        ll br=(y-1)/bl;

        ans-=count[bt];
        count[bt]=0;
        for(ll i=bt*bl;i<(bt+1)*bl;i++)
        {
            if(f[bt]==0 && i<x-1)
                a[i]=val[bt];
            else if(f[bt]==-1&&i>=x-1)
                a[i]=z;
            else if(f[bt]==0 && i>=x-1)
                a[i]=z;
            if(a[i]==b[i])
            {
              ans++;
              count[bt]++;
            }
        }

        f[bt]=-1;
        val[bt]=-1;

        for(int i=bt+1;i<br;i++)
        {
            ans-=count[i];
            count[i]=mp[i][z];
            ans+=count[i];
            f[i]=0;
            val[i]=z;
        }

        ans-=count[br];
        count[br]=0;
        for(ll i=br*bl;i<(br+1)*bl;i++)
        {
            if(f[br]==0 && i>y-1)
                a[i]=val[br];
            else if(f[br]==-1&&i<y)
                a[i]=z;
            else if(f[br]==0 && i<y)
                a[i]=z;
            if(a[i]==b[i])
            {
              ans++;
              count[br]++;
            }
        }
        f[br]=-1;
        val[br]=-1;
        cout<<ans<<endl;
    }
}
    return 0;
}
