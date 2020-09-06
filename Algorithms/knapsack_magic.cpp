/*
	You can multiply any i & j with  x & y respective,i!=j.
*/


 
#include<bits/stdc++.h> 
using namespace std;
 
#define MEM(a, b) memset(a, (b), sizeof(a))
#define ALL(a) a.begin(), a.end()
#define MP(a, b) make_pair(a, b)
#define PB(a, b) push_back(a)
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0),cout << fixed << setprecision(10);
#define ll long long 
#define int long long
#define DEBUG
 
#ifdef DEBUG
 
    #define debug(args...)(Debugger()) , args
 
    class Debugger{
        public:
        Debugger(const std::string& _separator = " | ") :
        first(true), separator(_separator){}
 
        template<typename ObjectType> Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << std::endl;}
 
        private:
        
        bool first;
        std::string separator;
    };
 
#else
    #define debug(args...)
#endif
 
const int N = 1e3 + 5;
 
int dp[N][N][4];
int a[N], b[N];
int n, w, x, y;
 
int fun(int pos, int wight, int rem){
 
	// debug(pos, wight, rem);
 
	if(pos >= n){
		return 0;
	}
 
	if(wight < 0){
		return INT_MIN;
	}
 
	if(dp[pos][wight][rem] != -1){
		return dp[pos][wight][rem];
	}
 
	dp[pos][wight][rem] = max(dp[pos][wight][rem], fun(pos+1, wight, rem));
	if((wight - a[pos]) >= 0){
		dp[pos][wight][rem] = max(fun(pos+1, wight - a[pos], rem) + b[pos], dp[pos][wight][rem]);
		if((rem & 1) == 0){
			dp[pos][wight][rem] = max(fun(pos+1, wight - a[pos], rem|1) + (b[pos]*x), dp[pos][wight][rem]);
		}
		if((rem&2) == 0){
			dp[pos][wight][rem] = max(fun(pos+1, wight - a[pos], rem|2) + (b[pos]*y), dp[pos][wight][rem]);	
		}
	}
	return dp[pos][wight][rem];
}
 
void solve(){
 
	MEM(dp, -1);
 
	cin >> n >> w >> x >> y;
 
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
 
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
 
	cout << fun(0, w, 0) << '\n';
}
 
int32_t main(){
 
	boost;
	int T;
	cin >> T;
	// T = 1;
	while(T--){
		solve();
	}
	return 0;
}