
// problem 2:https://www.codechef.com/COOK118A/problems/CHEFSHIP
// solution :https://www.codechef.com/viewsolution/33332670

// problem 2: https://codeforces.com/problemset/problem/514/C 
// solution:https://codeforces.com/contest/514/submission/66649593

const int M = 1e9 + 7;
const int p=31;

int mod(int n) {
    n%=M;
    n+=M;
    return n%M;
}

int power(int a,int b){
    int ans = 1;
    while(b>0){
        if(b&1)
            ans  = mod(ans*a);
        b/=2;
        a = mod(a*a);
    }
    return ans;
}

int modInv(int n){
    return power(n,M-2);
}


vector<int> compute_hash(string s) {
    int n = s.size();
    vector<int>v;
    int hash_value = 0;
    int p_pow = 1;
    for (char c : s) {
        hash_value = mod(hash_value + (c - 'a' + 1) * p_pow);
        p_pow = mod(p_pow * p);
        v.push_back(hash_value);
    }
    return v;
}
