int phi[N];

void totient() {
    iota(phi,phi+N,0);
    for(int i=2;i<N;i++) {
        if(phi[i]==i) {
            phi[i]=i-1;
            for(int j=2*i;j<N;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}
