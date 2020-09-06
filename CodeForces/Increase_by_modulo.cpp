/**
*    Incresing By Modulo
*   link: https://codeforces.com/contest/1169/problem/C
*   binary search in all constrain,check function check X is
     ans or not(NlonN)
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
int a[MAX],n,m;
bool check(int mid)
{
    int prev=0;
    //cout<<prev<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=prev)
        {
            if(prev >  mid + a[i])
                return false;
        }
        else
        {
            if(m+prev >mid + a[i])
                prev=a[i];
        }
    }
    return true;
}

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=0,r=m-1,ans=0;

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
}


