/**
*    -MAY circuit
*    -Ineffective guard
*    -link:https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/practice-problems/algorithm/jewellery-8cc358bc/
*    - Line Sweep Technique(NlogN)
*    - refrence :https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/tutorial/
*    - (x1 + y1) <= (x2 +y2) and (y1 - x1) >= (y2 -x2) count number
*                points (x1,y1),(x2,y2) satisfied both conditions
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
#define all(ve) ve.begin(),ve.end()

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m;
    cin>>n>>m;

    vector<pair<PI,int > > a;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({{x+y,y-x},i});
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({{x+y,y-x},-1});
    }

    sort(all(a));
    int cnt[n];
    memset(cnt,0,sizeof cnt);
    set<PI>guard;
    for(int i=0;i<a.size();i++)
    {
      if(a[i].ss!=-1)
      {
          guard.insert({a[i].ff.ss,a[i].ss});
          continue;
      }
      set<PI>::iterator it,it1;
      it = guard.lower_bound({a[i].ff.ss,0});
      if(it == guard.end())
         continue;
      it1=it;
      it1++;
      if(it1 == guard.end())
        cnt[it->ss]=1;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(cnt[i]==0)
            ans++;
    }
    cout<<ans<<endl;
}
