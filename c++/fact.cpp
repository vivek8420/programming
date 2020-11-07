
const int N = 5e5 + 5;
const int M = 1e9 + 7; //998244353;

int mod(int m, int mod = M) {
	m %= mod;
	return (m + mod) % mod;
}

int power(int x, int y) {
	int res = 1;
	x = mod(x);
	while (y > 0) {
		if (y & 1)
			res = mod(res * x);
		y = y / 2;
		x = mod(x * x);
	}
	return mod(res);
}

int f[N], invf[N];
void fact() {
	f[0] = f[1] = 1;
	for(int i = 2; i < N; i++)
		f[i] = mod(f[i - 1] * i);

	invf[N - 1] = power(f[N - 1], M - 2);
	for(int i = N - 1; i > 0; i--)
		invf[i - 1] = mod(invf[i] * i);
}

int nCr(int n, int r) {
	if(r > n)
		return 0;
	int ans = f[n];
	ans = mod(ans * invf[n - r]);
	ans = mod(ans * invf[r]);
	return ans;
}

int nPr(int n, int r) {
	if(r > n)
		return 0;
	int ans = f[n];
	ans = mod(ans * invf[n - r]);
	return ans;
}

