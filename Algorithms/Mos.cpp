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

