/**
*   author: vivek8420
*   link:https://www.hackerearth.com/challenges/competitive/june-circuits-19/algorithm/june-circuits-function-value-bdd25438/
*   time : log(n)
**/

/*   f(n+2) = 2*f(n+1) - f(n) + 2 if n is even
*   f(n+2) = 2*f(n) if n is odd
*   f[1]=f[2]=1
*   find f(l)+ f(l+1)+...+ f(r)
*/

//-> matrix exponation
// -> compute GP%M ,where M is any number

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define PI pair<int,int>
#define TP pair<PI,int>
#define ff first
#define ss second
#define ft ff.ff
#define st ff.ss
#define MAX 111111
#define INF INT_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

ll MOD;
ll mod(ll m)
{
    while(m<0)
        m+=MOD;
    return m%MOD;
}

ll mod1(ll m,ll p)
{
    while(m<0)
        m+=p;
    return m%p;
}

ll powerMod(ll x,ll y,ll p)
{
    ll res = 1;
    x = mod1(x,p);
    while (y > 0)
    {
        if (y & 1)
            res =mod1(res*x,p);
        y = y>>1;
        x = mod1(x*x,p);
    }
    return mod1(res,p);
}

void multiply(ll a[2][2], ll b[2][2],ll p)
{
	ll mul[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mul[i][j] = 0;
			for (int k = 0; k < 2; k++)
				mul[i][j] =mod1(mul[i][j]+ mod1(a[i][k]*b[k][j],p),p);
		}
	}

	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			a[i][j] = mul[i][j];
}

void power(ll F[2][2], ll n,ll p)
{
	ll M[2][2]={2,3,1,0};
	if (n==1)
		return;
	power(F, n/2,p);
	multiply(F, F,p);
	if (n%2 != 0)
		multiply(F, M,p);
	return ;
}

ll nthEven(ll n)
{
    if(n==2)
     return 1;
    if(n==4)
     return 7;
    if(n==6)
      return 13;
	ll F[2][2] = {2,3,1,0};
    power(F, n/2-3,2*MOD);
  return mod1(mod1(12*F[0][0],2*MOD)+mod1(6*F[0][1],2*MOD) + 1,2*MOD);
}

ll computeGP(ll r,ll n)
{
    ll ans = powerMod(r,n+1,(r-1)*MOD) -1;
    ans=ans/(r-1);
    return mod(ans);
}

ll odd(ll l,ll r)
{
    if(l%2==0)
        l++;
    if(r%2==0)
        r--;
    if(l>r)
        return 0;
   ll ans = mod(powerMod(3,l/2,MOD)*computeGP(3,(r-l)/2));
    return ans;
}

ll even(ll l,ll r)
{
    if(l%2==1)
        l++;
    if(r%2==1)
        r--;
    if(l>r)
        return 0;
    ll ans = mod((r-l)/2 + odd(l,r));
    ans =ans +mod((nthEven(l) + nthEven(r))/2);
    return mod(ans);
}


int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int t;
    cin>>t>>MOD;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        ll ans = mod(odd(l,r)+even(l,r));
        cout<<ans<<endl;
    }
}
