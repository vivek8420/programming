/*
	author : vivek8420
	problem : https://codeforces.com/contest/702/problem/E
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long

const int lg = 40;
const int N = 1e5 + 5;
int n,k;
int sum[lg][N],mn[lg][N],par[lg][N];

void compute_sparce() {
	for(int i=1;i<lg;i++){
		for(int j=0;j<N;j++){
			par[i][j] = par[i-1][par[i-1][j]];
			mn[i][j] = min(mn[i-1][j],mn[i-1][par[i-1][j]]);
			sum[i][j] = sum[i-1][j] + sum[i-1][par[i-1][j]];
		}
	}
}

void solve(int x){
	int ans = 0,mini = mn[0][x];
	for(int i=lg-1;i>=0;i--){
		if(k & (1ll<<i)) {
			ans += sum[i][x];
			mini = min(mini,mn[i][x]);
			x = par[i][x];
		}
	}
	cout<<ans<<" "<<mini<<endl;
}

int32_t main(){
	cin>>n>>k;
	for(int i=0,x;i<n;i++){
		cin>>x;
		par[0][i] = x;
	}
	for(int i=0,x;i<n;i++){
		cin>>x;
		mn[0][i] = x;
		sum[0][i] = x;
	}

	compute_sparce();
	
	for(int i=0;i<n;i++)
		solve(i);
}