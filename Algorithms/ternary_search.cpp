
//minimise answer
int ternary_search(int l, int r) {
	while(r - l > 2){
		int m1 = (2 * l + r) / 3;
		int m2 = (l + 2 * r) / 3;
		int t1 = cost(m1);
		int t2 = cost(m2);
		if(t1 <= t2)
			r = m2;
		else
			l = m1;
	}
	int ans = cost(l);
	for(int i = l + 1; i <= r; i++)
		ans = min(ans, cost(i));
	return ans;
}


//maximise ans
int ternary_search(int l, int r) {
	while(r - l > 2 ){
		int m1 = (2 * l + r) / 3;
		int m2 = (l + 2 * r) / 3;
		int t1 = cost(m1);
		int t2 = cost(m2);
		if(t1 <= t2)
			l = m1;
		else
			r = m2;
	}
	int ans = cost(l);
	for(int i= l + 1; i <= r; i++)
		ans = max(ans, cost(i));
	return ans;
}

