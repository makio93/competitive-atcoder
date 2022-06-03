// 自力AC

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

const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<int> a(n*2), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<vector<ll>> bh(30, vector<ll>(2)), ah(30, vector<ll>(n));
	rep(i, 30) rep(j, 2) rep(j2, n) bh[i][j] = (bh[i][j] * 2 + (((b[j2]>>i)&1) ^ j)) % mod;
	rep(i, n) a[n+i] = a[i];
	ll bt = 1;
	rep(i, n) bt = bt * 2 % mod;
	rep(i, 30) {
		rep(j, n) ah[i][0] = (ah[i][0] * 2 + ((a[j]>>i) & 1)) % mod;
		rep3(j, 1, n) ah[i][j] = (ah[i][j-1] * 2 - bt * ((a[j-1]>>i) & 1) + mod + ((a[j+n-1]>>i) & 1)) % mod;
	}
	vector<pair<int, int>> res;
	rep(i, n) {
		int x = b[0] ^ a[i];
		bool ok = true;
		rep(j, 30) if (ah[j][i] != bh[j][(x>>j)&1]) ok = false;
		if (ok) res.emplace_back(i, x);
	}
	if (!res.empty()) {
		sort(all(res));
		for (auto pi : res) cout << pi.first << ' ' << pi.second << endl;
	}
	else cout << endl;
	return 0;
}
