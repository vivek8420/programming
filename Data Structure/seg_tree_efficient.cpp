
int n;
class segment_tree_efficient
{
private:
    vector<int>tree;
    vector<int>a;
public:
    segment_tree_efficient(vector<int>&v){
        a = v;
        n = v.size();
        tree.resize(4*n);
    }

    void built() {
        for(int i=0;i<n;i++)  // insert leaf node
            tree[n+i]=a[i];
        for(int i=n-1;i>0;i--)   // calculate parents
            tree[i]=tree[i<<1]+tree[i<<1 | 1];
    }

    void update(int p,int val) {  // point update
        p=p+n;
        tree[p]=val;
        for (int i=p; i > 1; i >>= 1)   // move upward and update parents
             tree[i>>1] = tree[i] + tree[i^1];
    }

    int query(int l,int r) { // get sum in [l,r) interval
        int res=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if(l&1)
                res+=tree[l++];
            if(r&1)
                res+=tree[--r];
        }
        return res;
    }
};
