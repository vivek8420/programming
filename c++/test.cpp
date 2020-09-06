#include<bits/stdc++.h>
using namespace std;
#define int long long

string S = "abcdefghijklmnopqrstuvwxyz";
string D = "0123456789";

int r(int n);
void r_array(int n);
void r_2Darray(int n,int m);
void r_string(int n);
void r_permutation(int n);
void r_tree(int n,bool weight);
void r_cgraph(int n,int m,bool weight);
void r_graph(int n,int m,bool weight);
void r_dgraph(int n,int m,bool weight);

const int N = 5;
const int M =10;
const int A = 5;
const int C = 1;

int32_t main() {	
	#ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        freopen("input.txt","w",stdout);
    #endif // ONLINE_JUDGE
	srand(time(0));
	
	int t = 5;// + rand()%10;
	cout<<t<<endl;
	while(t--){
		int n = 5;
		int m = r(n * (n - 1) / 2);
		cout << n << ' ' << m << endl; 
		r_dgraph(n, m, 0);
		cout << endl;
	}
	return 0;
}

int r(int N){
	int tt = C + rand()%N;
	return tt;
}

void r_array(int n){
	for(int i=1;i<n;i++){
		int tt = r(A);
		cout<<tt<<" ";
	}
	int tt = r(A);
	cout<<tt<<endl;
}

void r_2Darray(int n,int m) {
	for(int i=0;i<n;i++)
		r_array(m);
}

void r_string(int n){
	string ans = "";
	for(int i=0;i<n;i++){
		int id = r(3)-1;
		ans += S[id];
	}
	cout<<ans<<endl;
}

void r_permutation(int n){
	set<int>s;
	vector<int>v;
	while(s.size() < n){
		int tt = r(n);
		if(s.find(tt) == s.end()){
			v.push_back(tt);
			s.insert(tt);
		}
	}
	for(auto &i:v)
		cout<<i<<" ";
	cout<<endl;
}

void r_tree(int n,bool f) {
	set<pair<int,int>>s;
	bool visit[n+1];
	function < bool (int, int) > dfs = [&](int u,int p) {
		visit[u] = true;
		bool okk = false;
		for(auto v : s) {
			if(v.first == u) {
				if(v.second == p)
					continue;
				if(visit[v.second])
					return true;
				okk |= dfs(v.second,u);
			}
			else if(v.second == u) {
				if(v.first == p)
					continue;
				if(visit[v.first])
					return true;
				okk |= dfs(v.first,u);
			}
		}
		return true;
	};
	auto cycle = [&] ( ) {
		memset(visit,false,sizeof false);
		bool okk = false;
		for(int i = 1; i <= n; i++) {
			if(visit[i])
				continue;
			okk |= dfs(i, 0);
		}
		return okk;
	};
	while(s.size() < n - 1){
		int u = r(n);
		int v = r(n);
		if(s.count({min(u,v),max(u,v)}) or u == v)
			continue;
		if(u > v)
			swap(u,v);
		s.insert({u,v});
		if(cycle()) {
			s.erase({u,v});
			continue;
		}
		cout<<u<<" "<<v;
		if(f){
			int w = r(A);
			cout<<" "<<w;
		}
		cout<<endl;
	}
}

void r_graph(int n,int m,bool f) {
	set<pair<int,int>>s;
	while(s.size() < m){
		int u = r(n);
		int v = r(n);
		if(s.count({min(u,v),max(u,v)}) or u == v)
			continue;
		cout<<u<<" "<<v;
		if(u > v)
			swap(u,v);
		s.insert({u,v});
		if(f){
			int w = r(A);
			cout<<" "<<w;
		}
		cout<<endl;
	}
}

void r_cgraph(int n,int m,bool f){
	if(m < n - 1){
		cout<<-1;
		return;
	}
	set<pair<int,int>>s;
	while(s.size() < n - 1){
		int u = r(n);
		int v = r(n);
		if(s.count({min(u,v),max(u,v)}) or u == v)
			continue;
		cout<<u<<" "<<v;
		if(u > v)
			swap(u,v);
		s.insert({u,v});
		if(f){
			int w = r(A);
			cout<<" "<<w;
		}
		cout<<endl;
	}	

	while(s.size() < m){
		int u = r(n);
		int v = r(n);
		if(s.count({min(u,v),max(u,v)}) or u == v)
			continue;
		cout<<u<<" "<<v;
		if(u > v)
			swap(u,v);
		s.insert({u,v});
		if(f){
			int w = r(A);
			cout<<" "<<w;
		}
		cout<<endl;
	}
}


void r_dgraph(int n,int m,bool f) {
	set<pair<int,int>>s;
	while(s.size() < m){
		int u = r(n);
		int v = r(n);
		if(s.count({u,v}) or u == v)
			continue;
		cout<<u<<" "<<v;
		s.insert({u,v});
		if(f){
			int w = r(A);
			cout<<" "<<w;
		}
		cout<<endl;
	}
}
