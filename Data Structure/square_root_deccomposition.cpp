
struct sqrt_decomposition 
{
	//0 based indexes
	int sz,block;
	vector<int>sum;
	void built_sqrt(int n,int *a) {
		sz=sqrt(n);
		block= n%sz==0 ? n/sz:n/sz+1;
		sum.resize(block+1);
		for(int i=0;i<n;i++)
		{
		   int bn=i/sz;
		   sum[bn]+=a[i];
		}
	}

	void point_update(int x,int val,int a[]) {
		int bn=x/sz;
		sum[bn]-=a[x];
		a[x]+=val;
		sum[bn]+=val;
	}

	void range_update(int l,int r,int val,a[]) {
		int bl=l/sz;
		int br=r/sz;

		for(int i=l;i<(bl+1)*sz;i++)
		{
			a[i]+=val;
			sum[bl]+=val;
		}

		for(int i=bl+1;i<br;i++) {
			// DO SOMETHING
		}

		for(int i=br*sz;i<=r;i++)
		{
			a[i]+=val;
			sum[l]+=val;
		}
	}

	int query(int l,int r,int a[])
	{
		int ans=0;
		int bl=l/sz;
		int br=r/sz;

		if(bl==rl)
		{
			for(int i=l;i<=r;i++)
				ans+=a[i];
			return ans;
		}
		for(int i=l;i<(bl+1)*sz;i++)
			ans+=a[i];
		for(int i=bl+1;i<br;i++)
			ans+=sum[i];
		for(int i=br*sz;i<=r;i++)
			ans+=a[i];
		return ans;
	}
}SRDC;
