
// find the number of poits lie in same line

// represent slope as pair
pi get_slope(pi p1, pi p2) {
	int x = p1.ff - p2.ff;
	int y = p1.ss - p2.ss;
	if(x == 0 && y == 0)
		return {1, 1};
	if(x == 0)
		y = 1;
	if(y == 0)
		x = 1;
	int g = __gcd(x, y);
	x /= g;
	y /= g;
	return {x, y};
}

int solve(vector < pi > &points, int pos) {
	int ans = 0;
	map < pi, int > mp;
	for(int i = pos + 1; i < points.size(); i++) {
		pi cur = get_slope(points[pos], points[i]);
		debug(pos, i, cur);
		mp[cur]++;
		ans = max(ans, mp[cur]);
	}
	return ans + 1;
}

int solve(vector < pi > &points) {
	if(points.size() < 3)
		return points.size();

	int ans = 2;
	for(int i = 0; i < points.size(); i++)
		ans = max(ans , solve(points, i));
	return ans;
}
