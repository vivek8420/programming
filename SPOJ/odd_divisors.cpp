/*
    author:vivek8420
    problem:Odd Numbers Of Divisors(ODDDIV)
    link:https://www.spoj.com/problems/ODDDIV/
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define PI pair<int,int>
#define TP pair<PI,int>
#define ff first
#define ss second
#define ft ff.ff
#define st ff.ss
#define MOD 998244353
#define INF INT_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 100000001

int divisor(int n) 
{
    int res = 1, i, c;
    for(i=2; i*i<=n; i++) 
    {
        if(n % i == 0)
        {
            c = 0;
            while(n % i == 0)
            {
                n /= i;
                c++;
            }
            res *= (2*c+1);   
        }
    }
    if(n>1) res *= 3;
    return res;  
}

int32_t main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    vector<int>mp[100005];

    for(int i=1;i<100000;i++)
    {
        int k=divisor(i);
        if(k%2==1 && k<10000)
            mp[k].push_back(i*i);
    }

    int t;
    cin>>t;
    while(t--)
    {
        int k,l,r;
        cin>>k>>l>>r;
        /*for(int i=0;i<mp[k].size();i++)
            cout<<mp[k][i]<<" ";
        cout<<endl;*/

        int ee=lower_bound(all(mp[k]),r+1)-mp[k].begin();
        int ss=lower_bound(all(mp[k]),l)-mp[k].begin();
        //cout<<ee<<" "<<ss<<endl;
        cout<<ee-ss<<endl;
    }
}
 