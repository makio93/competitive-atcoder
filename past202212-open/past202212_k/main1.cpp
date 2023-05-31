// 解説AC

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

const int INF = (int)(1.1e9);

int main() {
	int a, b;
	ll x;
	cin >> a >> b >> x;
	vector<unordered_map<int, int>> memo(100);
	function<int(int,int)> calc = [&](int y, int k) {
		if (memo[max(0, k)].find(max(0, y)) != memo[max(0, k)].end()) return memo[max(0, k)][max(0, y)];
		if (y<=0 || k<=0) return memo[max(0, k)][max(0, y)] = -INF;
		int rval = -INF, yval = y;
		if (k <= 9) rval = min(y, k);
		rep(i1, 10) {
			if (yval <= 0) break;
			int bval = yval % 10, tval = calc(min((int)(1e8), yval/10), k-bval);
			if (tval != -INF) rval = max(rval, (int)min((ll)(1e9), (ll)tval*10+bval));
			--yval;
		}
		return memo[k][y] = min((int)(1e9), rval);
	};
	int res = 1;
	rep3(i, 1, 100) res = max(res, calc((int)min((ll)(1e9), (x-(ll)b*i)/a), i));
	cout << res << endl;
	return 0;
}
