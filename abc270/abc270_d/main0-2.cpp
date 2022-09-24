// 本番AC

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

const int INF = (int)(1e9);

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	rep(i, k) cin >> a[i];
	vector<vector<int>> memo(2, vector<int>(n+1, -1));
	auto calc = [&](auto calc, int ri, int ni) -> int {
		if (memo[ri][ni] != -1) return memo[ri][ni];
		int rval = 0;
		if (ni == 0) return memo[ri][ni] = rval;
		rep(i, k) {
			if (a[i] > ni) break;
			int tval = calc(calc, 1-ri, ni-a[i]);
			rval = max(rval, a[i]+(ni-a[i]-tval));
		}
		return memo[ri][ni] = rval;
	};
	int res = calc(calc, 0, n);
	cout << res << endl;
	return 0;
}
