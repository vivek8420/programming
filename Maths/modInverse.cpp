

// Method1: a and m are c0-prime
int modInv(int a) {//extended euclid
	int m = M;
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
	  return 0;

	while (a > 1)
	{
		int q = a / m;
		int t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
	   x += m0;
	return x;
}

//// --> Method 2: m is prime
int power(int x,int y) {
	int res = 1;
	x = mod(x);
	while (y > 0)
	{
		if (y & 1)
			res =mod(res*x);
		y = y>>1;
		x = mod(x*x);
	}
	return mod(res);
}

int modInv(int a, int m = M) {
	int ans = power(a, m - 2);
	return ans % m;
}

// --> Method 3:
int gcdExtended(int a, int b,int *x, int *y) {
	if(a == 0) {
		*x = 0, *y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}


int  modInv(int a, int m) {
	int x,y;
	int g = gcdExtended(a, m, &x, &y);
	int res = (x % m + m) % m;
	return res;
}

