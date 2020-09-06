typedef struct seg_node {
	int sum = 0;
	int lazy = 0;
}sn;

sn merge(sn a,sn b) {
	sn tmp;
	tmp.sum = a.sum + b.sum;
	return tmp;
}

int n;
class lazy_segment_tree{
private:
	vector<sn>tree;
	vector<int>a;
public:
	lazy_segment_tree(vector<int>&v){
		a = v;
		n = v.size();
		tree.resize(4*v.size());
	}

	void lazy_update(int x,int ss,int ee) {
		if(tree[x].lazy == 0)
			return;
		tree[x].sum += tree[x].lazy;
		if(ss != ee) {
			tree[2*x].lazy += tree[x].lazy;
			tree[2*x+1].lazy += tree[x].lazy;
		}
		tree[x].lazy=0;
	}

	void built(int x=1,int ss=0,int ee=n-1) {
		if(ss==ee) {
			tree[x].sum =  a[ss];
			return;
		}
		int m=(ss+ee)/2;
		built(2*x,ss,m);
		built(2*x+1,m+1,ee);
		tree[x]=merge(tree[2*x],tree[2*x+1]);
	}

	void update(int l,int r,int val,int x=1,int ss=0,int ee=n-1) {
		lazy_update(x,ss,ee);
		if(ss>r || ee<l || l>r)
			return;
		if(ss>=l && ee <=r) {
			tree[x].lazy += val;
			lazy_update(x,ss,ee);
			return;
		}
		int m=(ss+ee)/2;
		update(l,r,val,2*x,ss,m);
		update(l,r,val,2*x+1,m+1,ee);
		tree[x]=merge(tree[2*x],tree[2*x+1]);
	}

	sn query(int l,int r,int x=1,int ss=0,int ee=n-1) {
		lazy_update(x,ss,ee);
		if(ss>r || ee<l || l>r)
			return tree[0];
		if(ss>=l && ee<=r)
			return tree[x];
		int m=(ss+ee)/2;
		sn p= query(l,r,2*x,ss,m);
		sn q = query(l,r,2*x+1,m+1,ee);
		sn ans = merge(p,q);
		return ans;
	}
};
