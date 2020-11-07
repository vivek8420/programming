
class Gauss {
private:
	vector < int > v;
	int bits;

public:
	Gauss() { 
		bits = 20;
		v.resize(bits, 0);
	}
	
	Gauss(int n) {
		bits = n;
		v.resize(bits, 0);
	}

	// add new elements
	void add(int x) {
		for(int i = bits - 1; i >= 0 && x; i--){
			if(v[i] == 0) {
				v[i] = x;
				break;
			}
			x = min(x, x ^ v[i]);
		}
	}

	// is x possible?
	bool isPresent(int x) { 
		for(int i = bits - 1; i >= 0 ; i--)
			x = min(x, x ^ v[i]);
		return (x == 0);
	}

	//size of basis
	int size() {
		int ans = 0;
		for(int i = 0; i < bits; i++)
			ans += (v[i] != 0);
		return ans;
	}

	// maximum possible xor
	int max_xor() {
		int ans = 0;
		for(int i = bits - 1; i >= 0; i--)
			ans = max(ans, ans ^ v[i]);
		return ans;
	}

	void merge(Gauss &a) {
		for(int i = bits - 1; i >= 0; i--)
			add(a.v[i]);
	}
};
