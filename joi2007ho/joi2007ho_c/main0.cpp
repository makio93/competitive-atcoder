// 学習0回目,自力AC1

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
	vector<vector<bool>> yx(5001, vector<bool>(5001));
	rep(i, n) yx[y[i]][x[i]] = true;
	int res = 0;
	rep(i, n) rep(j, n) if (i != j) {
		int dy = y[j] - y[i], dx = x[j] - x[i];
		int vy1 = -dx, vx1 = dy, vy2 = dx, vx2 = -dy;
		int r2 = dy * dy + dx * dx;
		auto exist = [&](int yi, int xi) -> bool {
			if (yi<0 || yi>5000 || xi<0 || xi>5000) return false;
			return yx[yi][xi];
		};
		if (exist(y[i]+vy1, x[i]+vx1) && exist(y[j]+vy1, x[j]+vx1)) res = max(res, r2);
		else if (exist(y[i]+vy2, x[i]+vx2) && exist(y[j]+vy2, x[j]+vx2)) res = max(res, r2);
	}
	cout << res << endl;
	return 0;
}
