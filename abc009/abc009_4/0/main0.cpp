// 学習0回目,自力AC,ヒントあり

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
	int k, m;
	cin >> k >> m;
	vector<unsigned> a(k), c(k);
	rep(i, k) cin >> a[i];
	rep(i, k) cin >> c[i];
	if (m <= k) cout << a[m-1] << endl;
	else {
		vector<vector<unsigned>> mat(k, vector<unsigned>(k));
		rep(i, k) mat[0][i] = c[i];
		rep(i, k-1) mat[i+1][i] = ~0U;
		auto mat_mul = [&](vector<vector<unsigned>> x, vector<vector<unsigned>> y) -> vector<vector<unsigned>> {
			vector<vector<unsigned>> ret(x.size(), vector<unsigned>(y.front().size()));
			rep(i1, (int)(x.size())) rep(j1, (int)(y.front().size())) rep(i2, (int)(x.front().size())) ret[i1][j1] ^= (x[i1][i2] & y[i2][j1]);
			return ret;
		};
		auto mat_pow = [&](vector<vector<unsigned>> x, int r) -> vector<vector<unsigned>> {
			vector<vector<unsigned>> ret(x.size(), vector<unsigned>(x.size()));
			rep(i1, (int)(x.size())) ret[i1][i1] = ~0U;
			while (r > 0) {
				if (r&1) ret = mat_mul(x, ret);
				x = mat_mul(x, x);
				r >>= 1;
			}
			return ret;
		};
		auto rmat = mat_pow(mat, m-k);
		unsigned res = 0;
		rep(i, k) res ^= (rmat[0][i] & a[k-i-1]);
		cout << res << endl;
	}
	return 0;
}
