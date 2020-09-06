/******
	***
	***		Test Generation Code
	***		Goes into This file. 
	***		Always be Careful with Constraints
	***
******/

#include <bits/stdc++.h>
using namespace std;
#include "string"
#define endl '\n'
#define PI pair<int,int>
#define ff first
#define ss second
#define int long long 
#define boost ios_base::sync_with_stdio(false);cin.tie(nullptr)

int seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l=0,int r=INT_MAX)
{return uniform_int_distribution<int>(l,r)(rng);}

int32_t main() {
	boost;
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		freopen("input.txt","w",stdout);  
	#endif
	int t=1;
	cout<<t<<"\n";
	while(t--)
	{
		//Random Tree
		int i,n=rnd(1,10),m=rnd(1,7);
		vector<pair<int,int>> edges;
		set<pair<int,int> > ge;
		for(i=2;i<=n;++i)
		edges.emplace_back(rnd(1, i - 1), i);
		vector<int> perm(n + 1); // re-naming vertices
		for(int i = 1; i <= n; ++i)
			perm[i] = i;
		random_shuffle(perm.begin() + 1, perm.end());
		random_shuffle(edges.begin(), edges.end()); // random order of edges
		for(pair<int, int> edge : edges) {
			int a = edge.first, b = edge.second;
			if(perm[a]>perm[b]) {
				swap(a, b); // random order of two vertices
			}
			ge.insert({perm[a],perm[b]});
			// cout<<perm[a]<<" "<<perm[b]<<"\n";
			// printf("%d  %d\n", perm[a], perm[b]);
		}
		while(ge.size()<m){
			int p=rnd(1,n),q=rnd(1,n);
			if(p==q)
				continue;
			if(p>q)
				swap(p,q);
			ge.insert({p,q});
		}
		int x=rnd(1,n/2);
		set<int> a;
		while(a.size()<x){
			a.insert(rnd(1,n));
		}
		cout<<n<<" "<<m<<" "<<x<<"\n";
		for(auto &i:a){
			cout<<i<<" ";
		}
		cout<<"\n";
		for(auto &e:ge){
			cout<<e.first<<" "<<e.second<<"\n";
		}
	}
	return 0;
}
