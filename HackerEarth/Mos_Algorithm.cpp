/**
*   MOS-Algorithm,sqrt decomposition
*   author:vivek8420
*   refrence:https://www.hackerearth.com/practice/notes/mos-algorithm/
*   V([L, R]) = ∑i=0..99 count(i)^2 * i
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
#define MAX 111111
#define MOD 1000000007
#define INF INT_MAX
#define MINF INT_MIN
#define all(ve) ve.begin(),ve.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)


vector<ll> ans(MAX);
vector<TP> queries;
ll a[MAX];

struct Mos_Algorithm
{
  vector<ll>cnt;
  ll cur_ans=1;
  int BLOCK_SIZE,n,q;
  ll cnt[MAX];

      void init(int n1,int q1)
      {
          n=n1;
          q=q1;
          memset(cnt,0,sizeof cnt);
      }

    bool mo_cmp(TP x,TP &y)
    {
        int block_x = x.ft/ BLOCK_SIZE;
        int block_y = y.ft/ BLOCK_SIZE;
        if(block_x != block_y)
            return block_x < block_y;
        return x.first.second < y.first.second;
    }

    void add(int x)
    {
        cur_ans -= cnt[x] * cnt[x] * x;
        cnt[x]++;
        cur_ans+= cnt[x] * cnt[x] * x;
    }

    void remove(int x)
    {
        cur_ans -= cnt[x] * cnt[x] * x;
        cnt[x]--;
        cur_ans += cnt[x] * cnt[x] * x;
    }

    void mos()
    {
        sort(queries.begin(), queries.end(), mo_cmp);
        int ml=0,mr=n-1;
        for(int i=0;i<q;i++)
        {
            int l,r;
            l=queries[i].ft;
            r=queries[i].st;

            while(mr < r) {
                mr++;
                add(a[mr]);
            }
            while(mr > r) {
                remove(a[mr]);
                mr--;
            }

            while(ml< l) {
                remove(a[ml]);
                ml++;
            }
            while(ml > l) {
                ml--;
                add(a[ml]);
            }
            ll tmp=modInverse(cur_ans,MOD);
            ans[queries[i].ss] = mod(fact[r-l+1]*tmp);
        }
    }
}MOS;

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE
    factorial();
    int n,q;
    cin>>n>>q;
    MOS.init(n,q);

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        queries.push_back({{l,r},i});
    }
    MOS.mos();
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
}


