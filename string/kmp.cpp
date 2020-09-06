/*
*   author:vivek8420
*   problem:Pattern Find - NAJPF (SPOJ)
*   link:https://www.spoj.com/problems/NAJPF/
*/

vector<int> preffix(string s) {
	int n = s.size();
	vector< int > pi(n,0);
	for(int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while(j > 0 and s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			pi[i] = j + 1;
	}
	return pi;
}

vector<int> kmp(string t, string p) {
	vector<int> ans;
	int n = t.size();
	int m = p.size();
	vector<int> pi = preffix(p);
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j > 0 and t[i] != p[j])
			j = pi[j - 1];
		if(t[i] == p[j]) {
			j++;
			if(j == m) {
				ans.push_back(i - j + 1);
				j = pi[j - 1];
			}
		}
	}
	return ans; 
}

