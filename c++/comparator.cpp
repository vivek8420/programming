
1.using struct or class for extern data

// for priority_queue
struct cmp {
	bool operator()(int &a, int &b) {
		if(cnt[1][a]*cnt[0][b]<cnt[1][b]*cnt[0][a])
			 return true;
		return false;
	}
};


2.using function 

bool cmp(int &a,int &b) {
	return a<b;
}


3.using lambda expresion

sort(g[i].begin(),g[i].end(),[&](int &a,int &b){
	return  cnt[1][a]*cnt[0][b]<cnt[1][b]*cnt[0][a];
});
