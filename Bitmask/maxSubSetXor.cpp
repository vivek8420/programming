
// find maximum xorSum of any subset of given array
int maxSubSetXor(int *a,int n) {
	int ans = 0;
	int id = 0;
	for(int i = 61; i >= 0; i--) {
		int maxid  = -1, maxi = -1;
		for(int j = id; j < n; j++) {
			if( a[j] & (1ll << i) && a[j] > maxi) {
				maxi = a[j];
				maxid = j;
			}
		}
		if(maxid == -1)
			continue;
		swap(a[maxid] , a[id]);
		for(int j = 0; j < n; j++) {
			if(j != id && a[j] & (1ll << i) )
				a[j] ^= maxi;
		}
		id++;
	}

	for(int i = 0; i < n; i++)
		ans ^= a[i];
	return ans;
}


//https://atcoder.jp/contests/abc141/tasks/abc141_f
// divide given array into 2 set such way that maximize
// ans = xorSum(set1) + xorSum(set2)

int XorSum2Set(int *a, int n) {
	int ans = 0;
	for(int i = 0; i < n; i++) 
		xr ^= a[i];
	for(int i = 0; i < n; i++)
		a[i] &= ~xr;
	int ans  = maxSubSetXor(a, n);
	ans = 2 * ans + xr;
	return ans;
} 

