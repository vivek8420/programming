int fact[N];
int mod(int n) {
    n%=M;
    return (n+M)%M;
}

int modInv(int a) //extended euclid
{
    int m=M;
    int m0 = m;
    int y = 0, x = 1;

    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m= a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}

void factorial()
{
    fact[0]=1;
    for(int i=1;i<MAX;i++)
        fact[i]=mod(fact[i-1]*i);
}

int nCr(int n,int r) {
    if(r>n) return 0;
    int ans=fact[n];
    ans=mod(ans*modInv(fact[r]));
    ans=mod(ans*modInv(fact[n-r]));
    return ans;
}

int nPr(int n,int r) {
    int ans=fact[n];
    ans=mod(ans*modInv(fact[n-r]));
    return ans;
}
