vector<PI>pfact;
void prime_factor(int n) {
    pfact.clear();
    int cnt=0;
    while (n % 2 == 0){
        n = n/2;
        cnt++;
    }
    if(cnt)
        pfact.push_back({2,cnt});
   for (int i = 3; i <= sqrt(n); i = i + 2){
        cnt=0;
        while (n % i == 0){
            n = n/i;
            cnt++;
        }
        if(cnt)
            pfact.push_back({i,cnt});
    }
    if (n > 2)
        pfact.push_back({n,1});
}
