/**
*    bitwise OR sum of all orderded pairs (i,j),1<=i,j<=N
*   ex. n=3
*   ans= (1|1 + 1|2 + 1|3 + 2|1 + 2|2 + 2|3 + 3|1 + 3|2 +3|3)
*   refrence:https://stackoverflow.com/questions/39149909/all-pair-bitwise-or-sum
**/



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

ll mod(ll m)
{
    while(m<=MOD)
        m+=MOD;
    return m%MOD;
}

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    ll n,ans=0;
    cin>>n;

    for(int i=0;i<32;i++)
    {
        ll k=0;
        for(int j=1;j<=n;j++)
            if(!(j & (1<<i)))
              k++;
        ans = mod(ans + mod((1<<i)*(mod(n*(n-1)/2) -  mod(k*(k-1)/2))));
    }
    ans=mod(2*ans+mod(n*(n+1)/2));
    cout<<ans<<endl;
}


