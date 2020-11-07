/**
*   Fenwick Tree (Binary Index Tree)
*   author: savaliya_vivek
*   problem:SUBPRNJL (CodeChef)
*   link:https://www.codechef.com/problems/SUBPRNJL/
**/

template <typename T>
class fenwick_tree
{
private:
	vector<T> bit;
	int n;
public:
	fenwick_tree(int size){
		n = size + 1;
		bit.assign(n, {0});
	}
	
	void update(int x, T val){
		if(x == 0)
			bit[x] += val;
		while(x > 0){
			bit[x] += val;
			x -= (x & (-x));
		}
	}

	T query(int x){
		T ans = {0};
		if(x == 0)
			return ans;
		while(x < n){
			ans += bit[x];
			x += (x & (-x));
		}
		return ans;
	}
};

int findKthSmallest(int k, int n) {   
	int l = 0, r = n, ans;
	fenwick_tree<int> ft(n);
	while (l <= r) {
		int mid = (l + r) / 2;
		if (k <= ft.query(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	return ans;
}

