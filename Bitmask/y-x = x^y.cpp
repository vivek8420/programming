

// find y - x = x ^ y && L <= x <= y <= R

int dp[60][2][2][2];
int L,R;
int solve(int id, int l, int r, int cur) {
	if(id < 0)
		return 1;
	int &tmp = dp[id][l][r][cur];
	if(tmp != -1)
		return tmp;
	tmp = 0;
	if(l  or !((L >> id) & 1ll))
		tmp = mod(tmp + solve(id - 1, l, r | ((R >> id) & 1ll), cur) );

	if((l or !((L >> id) & 1LL)) && (r or ((R >> id) & 1ll)) && cur)
		tmp = mod(tmp + solve(id - 1, l, r, cur));
	if(r or ((R >> id) & 1ll))
		tmp = mod(tmp  + solve(id - 1, l | !((L >> id) & 1ll) , r, 1) );
	return tmp;
}


// ans = solve(59,0,0,0)