#include <bits/stdc++.h>
using namespace std;
#include "string"
#define int long long
#define pi pair < int, int>
#define ff first
#define ss second
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"

vector < int > a;
vector < int > f = {1, 1, 2, 6, 24, 120, 720};
int dp[8][25][8][8];

int solve(int id, int cnt, int box1, int box2) {
	if(cnt < 0) return 0;
	if(id >= a.size()) {
		if(cnt == 0 && box1 == box2)
			return 1;
		else
			return 0;
	}
	//int &tmp = dp[id][cnt][box1][box2];
	//if(tmp != -1)
		//return tmp;
	int tmp = 0;
	for(int i = 0; i <= min(a[id], cnt); i++) 
		tmp += solve(id + 1, cnt - i, box1 + (i > 0), box2 + (a[id] > i)) * f[i] * f[a[id] - i];
	debug(id, cnt, box1, box2, tmp);
	return tmp;
}

int32_t main() {
   boost;
   int n;
   cin >> n;
   a.resize(n);
   int sum  = 0;
   for(int &i : a ) {
   	cin >> i;
   	sum += i;
   }
   memset(dp, -1, sizeof dp);
   int ans = solve(0,sum / 2, 0, 0);
   cout << ans << endl;
}