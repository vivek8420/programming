/**
*   persistance segment tree
*   segment tree with lazy prapogation(range copy)
*   author:savaliya_vivek
*   problem:TWOARR(codechef)
*   link:https://www.codechef.com/problems/TWOARR
*   status:wrong answer
**/

typedef struct SegNode
{
    int l,r;
    int val;
}sn;


int n;
class persistance_segment_tree
{
private:
    int sz=0,root;
    vector<sn>tree;
    vector<int>a;

public:
    persistance_segment_tree(vector<int>&v){
        a = v;
        n = v.size();
        tree.resize(4*n);
    }

    int newleaf(int value) {
        int p =++sz;
        tree[p].l = tree[p].r = 0;
        tree[p].val = value;
        return p;
    }

    int newparent(int left,int right) {
        int p = ++sz;
        tree[p].l = left;
        tree[p].r = right;
        tree[p].val = tree[left].val + tree[right].val;
        return p;
    }

    int built(int ss=0,int ee=n-1) {
        if(ss==ee)
            return newleaf(arr[ss]);
        int mid=(ss+ee)/2;
        int left=built(ss,mid);
        int right=built(mid+1,ee);
        return newparent(left,right);
    }

    int point_update(int pos,int val ,int x=1,int ss=0,int ee=n-1){
        if(ss==ee)
            return newleaf(val);
        int mid=(ss+ee)/2;
        if(pos<=mid)
            return newparent(point_update(pos,val,tree[x].l,ss,mid),tree[node].r);
        else
            return newparent(tree[node].l,point_update(pos,val,tree[x].r,mid+1,ee));
    }

    int query(int l,int r,int x=1,int ss=0,int ee=n-1) {
        if(ee<l || ss>r)
            return 0;
        if(l<=ss && r>=ee)
            return tree[x].val;
        int mid=(ss+ee)/2;
        int p=query(l,r,tree[x].l,ss,mid);
        int q=query(l,r,tree[x].r,mid+1,ee);
        return p+q;
    }
};


