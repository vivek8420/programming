typedef struct segnode {
	int ans = 0;
	segnode operator + (const segnode &b) {
		segnode tmp;
		tmp.ans = ans + b.ans;
		return tmp;
	}
}sn;


sn merge(sn a, sn b) {
	return a + b;
}

int n;

class segment_tree{
private:
	vector< int > a;
	vector< sn > tree;

public:
	segment_tree(vector < int > &v){
		n = v.size();
		a = v;
		tree.resize(4 * n);
	}
	void built(int x = 1,int ss = 0,int ee = n - 1) {
		if(ss == ee) {
			tree[x] = {a[ss]};
			return;
		}
		int m = (ss + ee) / 2;
		built(2 * x, ss, m);
		built(2 * x + 1, m + 1, ee);
		tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
	}

	void update(int pos,int val,int x = 1,int ss = 0,int ee = n - 1) {
		if(ss>pos || ee<pos || ss>ee)
			return;
		if(ss == ee) {
			tree[x] = {val};
			return;
		}
		int m = (ss + ee) / 2;
		update(pos, val, 2 * x, ss, m);
		update(pos, val, 2 * x + 1, m + 1, ee);
		tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
	}

	sn query(int l, int r, int x = 1, int ss = 0, int ee = n - 1) {
		if(ss > r || ee < l ||ss > ee)
			return tree[0];
		if(l <= ss && r >= ee)
			return tree[x];
		int m = (ss + ee) / 2;
		sn p=query(l, r, 2 * x, ss, m);
		sn q=query(l, r, 2 * x + 1, m + 1, ee);
		return merge(p, q);
	}
};

