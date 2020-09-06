

int mu[N],prime[N];
void mobius() {
	fill_n(mu, N , 1);
	memset(prime, true, sizeof prime);
	for(int i = 2; i < N; i++) {
		if(i * i  < N)
			mu[i * i] = 0;
		if(prime[i])
			mu[i] = -1;
		for(int j = 2 * i; j < N; j += i) {
			mu[j] *= mu[i];
			prime[j] = false;
		} 
	}
}
