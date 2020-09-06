/**
*   author:vivek8420
*   problem:Pairs
*   link:https://codeforces.com/contest/1169/problem/B
*   select x and y atleast one of them is in all pairs
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 111111
#define MOD 1000000007


int main()
{
    boost;

    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m;
    cin>>n>>m;
    int a[m+1],b[m+1];
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i];
    vector<int>ve={a[1],b[1]};

    for(int i=0;i<2;i++)
    {
        int cnt=0;
        vector<int>f(n+1);

        for(int j=1;j<=m;j++)
        {
            if(a[j]!=ve[i] && b[j]!=ve[i])
            {
                cnt++;
                f[a[j]]++; // a[j] != b[j]
                f[b[j]]++;
            }
        }

        if(*max_element(f.begin(),f.end())==cnt)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}

