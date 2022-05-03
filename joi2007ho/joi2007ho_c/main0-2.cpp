// 学習0回目,自力AC2

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	set<pair<int, int>> yx;
	rep(i, n) yx.emplace(y[i], x[i]);
	int res = 0;
	rep(i, n) rep(j, n) if (i != j) {
		int dy = y[j] - y[i], dx = x[j] - x[i];
		int vy1 = -dx, vx1 = dy, vy2 = dx, vx2 = -dy;
		int r2 = dy * dy + dx * dx;
		if (yx.find({y[i]+vy1,x[i]+vx1})!=yx.end() && yx.find({y[j]+vy1,x[j]+vx1})!=yx.end()) res = max(res, r2);
		else if (yx.find({y[i]+vy2,x[i]+vx2})!=yx.end() && yx.find({y[j]+vy2,x[j]+vx2})!=yx.end()) res = max(res, r2);
	}
	cout << res << endl;
	return 0;
}
