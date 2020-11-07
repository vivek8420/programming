vector<pair<int, int>>  prime_factor(int n) {
	vector<pair<int, int>> ans;
	int cnt = 0;
	while (n % 2 == 0){
		n /= 2;
		cnt++;
	}
	if(cnt)
		ans.push_back({2, cnt});
   for(int i = 3; i <= sqrt(n); i += 2) {
		cnt = 0;
		while(n % i == 0) {
			n /= i;
			cnt++;
		}
		if(cnt)
			ans.push_back({i, cnt});
	}
	if(n > 1)
		ans.push_back({n, 1});
	return ans;
}
