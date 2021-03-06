
typedef complex < double > base ;
const double PI = acos(-1);

void fft(vector<base> &a,bool invert){
	int i,j,n=a.size();
	for(i=1,j=0;i<n;++i){
		int bit=n>>1;
		for(;j>=bit;bit>>=1){
			j-=bit;
		}
		j+=bit;
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	for(int len=2;len<=n;len<<= 1){
		double ang=2*PI/len*(invert?-1:1);
		base wlen(cos(ang),sin(ang));
		for(i=0;i<n;i+=len){
			base w(1);
			for(j=0;j<len/2;++j){
				base u=a[i+j],v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if(invert){
		for(i=0;i<n;++i){
			a[i]/=n;
		}
	}
}

void multiply(const vector<int> &a,const vector<int> &b,vector <int> &res){
	vector<base> fa(a.begin(),a.end()),fb(b.begin(),b.end());
	size_t n=1;
	while(n<max(a.size(),b.size())) n<<=1;
	n<<= 1;
	fa.resize(n),fb.resize(n);
	fft(fa,false),fft(fb,false);
	for(size_t i=0;i<n;++i){
		fa[i]*=fb[i];
	}
	fft(fa,true);
	res.resize(n);
	for(size_t i=0;i<n;++i){
		res[i]=((int)(fa[i].real()+0.5)>0);
	}
}


// find kth power of polynomial a
vector<int> power_poly(vector<int>&a,int n) {
	vector<int>res;
	res.push_back(1);
	while(n>0){
		if(n&1)
			multiply(res,a,res);
		multiply(a,a,a);
		n /= 2;
	}
	return res;
}

