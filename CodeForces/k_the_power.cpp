/*
	author:vivek8420
	problem:The sum of K-th Powers
	link:https://codeforces.com/contest/622/problem/F
	compexity:klog(k)
	1^k+2^k+...+n^k
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define MOD 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

int mod(int n)
{
	while(n<MOD)
		n+=MOD;
	return n%MOD;
}	

int power(int a, int b, int p)
{
    if(a == 0)
        return 0;
    int ans = 1;

    a = a%p;
    while(b>0)
    {
        if(b&1)
            ans = (ans*a)%p;

        b = b>>1;
        a = (a*a)%p;
    }
    return ans;
}

int modInverse(int a,int p)
{
    int tmp = p;
    int t2 = 0,t1 = 1;

    if(p == 1)
        return 0;

    while(a>1)
    {
        int q = a/p;
        int t = p;

        p = a%p;
        a = t;
        t = t2;

        t2 = t1 - q*t2;
        t1 = t;
    }

    if(t1 < 0)
        t1 = t1 + tmp;

    return t1;
}

int add(int a,int b)
{
    int ans = (a + b)%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}

int sub(int a,int b)
{
    int ans = (a - b)%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}

int mul(int a,int b)
{
    int ans = (a * b)%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}

int mdiv(int a,int b)
{
    int ans = (a * modInverse(b,MOD))%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}


// 1^k + 2^k + 3^k + ... + n^k
int value1(int n,int k)
{
    vector<int> y;

    int sum = 0,i;
    y.push_back(0);

    for(i=1;i<=k+1;i++)
    {
        sum = add(sum,power(i,k,MOD));
        y.push_back(sum);
    }

    if(n <= k+1)
        return y[n];

    sum = 0;

    int lag = 1;
    for(i=1;i<y.size();i++)
    {
        lag = mul(lag,sub(n,i));
        lag = mdiv(lag,sub(0,i));
    }

    for(i=0;i<y.size();i++)
    {
        sum = add(sum,mul(lag,y[i]));
        if((i+1) >= y.size())
            break;

        lag = mul(lag,mdiv(sub(n,i),sub(n,i+1)));
        lag = mul(lag,mdiv(sub(i,y.size() - 1),sub(i+1,0)));
    }
    return sum;
}

int32_t main()
{
	boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
	
	int n,k;
	cin>>n>>k;
	int ans=value1(n,k);
	cout<<ans<<endl;
}
