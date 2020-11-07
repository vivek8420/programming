/**
*   merge-sort tree
*   author:vivek8420
*   problem:MKTHNUM(SPOJ)
*   link:https://www.spoj.com/problems/MKTHNUM/
**/


int n;
class merge_sort_tree
{
private:
	vector<vector<int>> tree;
	vector<int> a;

public:
	merge_sort_tree(vector<int>& v){
		a = v;
		n = v.size();
		tree.resize(4 * n);
	}

	void built(int x = 1,int ss = 0,int ee = n - 1) {
		if(ss == ee) {
			tree[x].push_back(a[ss]);
			return;
		}
		int mid = (ss + ee) / 2;
		built(2 * x, ss, mid);
		built(2 * x + 1, mid + 1, ee);
		merge(tree[2 * x].begin(),tree[2 * x].end(),tree[2 * x + 1].begin(),tree[2 * x + 1].end(),back_inserter(tree[x]));
	}

	int query(int l, int r, int val, int x = 1, int ss = 0, int ee = n - 1) {
		if(ss > r || ee < l)
			return 0;
		if(ss >= l && ee <= r) {
			int tmp = upper_bound(tree[x].begin(), tree[x].end(), val) - tree[x].begin();
			return tmp;
		}
		int m = (ss + ee) / 2;
		int p = query(l, r, val, 2 * x, ss, m);
		int q = query(l, r, val, 2 * x + 1,m + 1, ee);
		return p + q;
	}
};

