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
using mint = modint998244353;

int main() {
	int n, m, a, b, c, d, e, f;
	cin >> n >> m >> a >> b >> c >> d >> e >> f;
	set<pair<int, int>> xy;
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		xy.emplace(xi, yi);
	}
	map<pair<int, int>, mint> dp, ndp;
	dp[{ 0, 0 }] = 1;
	rep(i, n) {
		for (auto& pi : dp) {
			if (xy.find({ pi.first.first+a, pi.first.second+b }) == xy.end()) {
				ndp[{ pi.first.first+a, pi.first.second+b }] += pi.second;
			}
			if (xy.find({ pi.first.first+c, pi.first.second+d }) == xy.end()) {
				ndp[{ pi.first.first+c, pi.first.second+d }] += pi.second;
			}
			if (xy.find({ pi.first.first+e, pi.first.second+f }) == xy.end()) {
				ndp[{ pi.first.first+e, pi.first.second+f }] += pi.second;
			}
		}
		swap(ndp, dp);
		ndp.clear();
	}
	mint res = 0;
	for (auto& pi : dp) res += pi.second;
	cout << res.val() << endl;
	return 0;
}
