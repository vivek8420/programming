
bool prime[N];
void sieve() {
	memset(prime,true,sizeof prime);
	prime[1]=false;
	for(int i=2;i*i<N;i++) {
	      if(prime[i])
	      for(int j=i*i;j<N;j+=i)
	      	prime[j]=false;
	}
}


// shortest prime factor using sieve
int spf[N];
void sieve(){
	iota(spf,spf+N,0);
	for(int i=2;i*i<N;i++){
		if(spf[i]==i){
			for(int j=i*i;j<N;j+=i){
				if(spf[j]==j)
					spf[j]=i;
			}
		}
	}
}

// prime factoer of N ,log(N)
vector<pi> prime_factor(int n){
	vector<pi>ans;
	while(n>1){
		int tmp=spf[n],cnt=0;
		while(spf[n]==tmp){
			n/=spf[j];
			cnt++;
		}
		ans.push_back({tmp,cnt});
	}
	return ans;
}
