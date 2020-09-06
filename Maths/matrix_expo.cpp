const int M = 1e9 + 7;
template<typename T>
T add(T a,T b) {
	T ans=a+b;
    ans%=M;
	return ans;
}
 
template<typename T>
T mul(T a,T b) {
	T ans=((T)a*(T)b)%M;
	return ans;
}
 
template<typename T>
class matrix
{
public:
	vector<vector<T>> mat;
	int dim;
	matrix(vector < vector < T >> m) {
		mat = m;
		dim = mat.size();
	}

	matrix(int _dim) {
		dim=_dim;
		mat=vector<vector<T>> (dim);
		for(int i=0;i<dim;i++)
			mat[i]=vector<T> (dim);
	}

	void reset() {
		for(int i=0;i<dim;i++) {
			for(int j=0;j<dim;j++) {
				mat[i][j]=(T)0;
			}
		}
	}

	void makeiden() {
		reset();
		for(int i=0;i<dim;i++)
			mat[i][i]=(T)1;
	}

	matrix<T> operator + (const matrix<T> &m) const 
	{
		matrix<T> res(dim);
		for(int i=0;i<dim;i++) {
			for(int j=0;j<dim;j++)
				res.mat[i][j]=add(mat[i][j],m.mat[i][j]);
		}
		return res;
	}

	matrix<T> operator * (const matrix<T> &m) const
	{
		matrix<T> res(dim);
		for(int i=0;i<dim;i++) {
			for(int j=0;j<dim;j++) {
				res.mat[i][j]=0;
				for(int k=0;k<dim;k++)
					res.mat[i][j]=add(res.mat[i][j],mul(mat[i][k],m.mat[k][j]));
			}
		}
		return res;
	}
};
 
template<typename T>
matrix<T> power(matrix<T> a,int b) {
	matrix<T> res(a.dim);
	res.makeiden();
	while(b>0) {
		if(b & 1)
			res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
