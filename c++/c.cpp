#include <bits/stdc++.h>
using namespace std;
#include "string"
#define int long long
#define pi pair < int, int>
#define ff first
#define ss second
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define all(v) v.begin(), v.end()

int32_t main() {
	boost;
	int n;
	cin >> n;
	vector < pi > v1,v2,v3;

	for(int i = 0; i < n; i++) {
		int x;
		char c;
		cin >> x >> c;
		if(c == 'R')
			v1.push_back({x,1});
		else if(c == 'B')
			v2.push_back({x,2});
		else
			v3.push_back({x,3});
	}

	sort(all(v1));
	sort(all(v2));
	sort(all(v3));

	int ans = 0;
	map < pi , int > mp;
	int l = 0,r = 0;
	for(int i = 0; i < v3.size() - 1;i++) {
		while(l < v1.size() && v1[l].ff < v3[i].ff)
			l++;
		while(r < v2.size() && v2[r].ff < v3[i].ff)
			r++;
		if(l == v1.size() or r == v2.size())
			break;
		if(v1[l].ff >= v3[i].ff && v1[l].ff <= v3[i + 1].ff && v2[r].ff >= v3[i].ff && v2[r].ff <= v3[i + 1].ff) {
			ans += (v3[i + 1].ff - v3[i].ff);
			mp[{v3[i].ff,v3[i + 1].ff}] = 1;
		}
	}
	
	cout << ans << endl;
}