/**
*   author: vivek8420
*   link : https://www.hackerearth.com/challenges/competitive/barclays-india-hackathon-2019-round-2-indicidual-challenge/algorithm/count-prefix-759edf57/
*   cordinate_compression,lower_bound
*   -- all the elements in the prefix of range [l,r] are divisible by k
*   time : O(n*sqrt(max(a[i]) + q*lonN*lonN)
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
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

map<ll,ll>dc;
vector<ll>ve[MAX];
ll cnt=1;

ll co(ll l)
{
    if(dc[l]==0)
    {
        dc[l]=cnt;
        cnt++;
    }
    return dc[l];
}
void divisors(ll n,int p)
{
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                ve[co(i)].push_back(p);
            else
            {
                ve[co(i)].push_back(p);
                ve[co(n/i)].push_back(p);
            }
        }
    }
}

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        divisors(a[i],i);
    }

    int q;
    cin>>q;
    while(q--)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        k = co(k);
        /*for(int p:ve[k])
          cout<<p<<" ";
         cout<<endl;
         */
         if(ve[k].size()==0)
         {
             cout<<-1<<endl;
             continue;
         }
        auto l1 =lower_bound(all(ve[k]),l);
        //cout<<*l1<<endl;
        if(*l1!=l)
            cout<<-1<<endl;
        else
        {
            ll s=l,e=r;
            ll ans=l;
            while(s<=e)
            {
                ll m = s+(e-s)/2;
                auto l2 = lower_bound(all(ve[k]),m);
                //cout<<s<<" "<<e<<" "<<m<<" "<<*l1<<" "<<*l2<<endl;
                if(*l2 !=m || l2-l1 < m-l)
                {
                    e=m-1;
                }
                else
                {
                    s=m+1;
                    ans=m;
                }
            }
            cout<<ans<<endl;
        }
    }
}

