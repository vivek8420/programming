#include "bits/stdc++.h"
using namespace std;
#include "string"
#define int long long
#define pi pair<int,int>
#define ff first
#define ss second
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#define endl '\n'
#define vi vector<int>

const int N = 1e3 + 3;

int count_cost(string s, strint t) {
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1' && t[i] == '0')
			return s.size() + 1;
		cnt += (s[i] == '0' && t[i] == '1');
	}
	return cnt;
}
int32_t main() {
	boost;
	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	int cost = 1e9;
	for(int i = 0; i < n; i++) {

	}
}