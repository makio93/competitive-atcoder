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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	b.insert(b.end(), all(b));
	reverse(all(b));
	vector<vector<ll>> alst(5, vector<ll>(n)), blst(5, vector<ll>(n*2)), arlst(5, vector<ll>(n)), brlst(5, vector<ll>(n*2));
	rep(i, 5) rep(j, n) {
		alst[i][j] = ((a[j] >> i) & 1);
		arlst[i][j] = 1 - alst[i][j];
	}
	rep(i, 5) rep(j, n*2) {
		blst[i][j] = ((b[j] >> i) & 1);
		brlst[i][j] = 1 - blst[i][j];
	}
	vector<vector<ll>> clst(5, vector<ll>(n));
	vector<ll> c0, c1, c2;
	rep(i, 5) {
		c0 = convolution_ll(alst[i], blst[i]);
		c1 = convolution_ll(alst[i], brlst[i]);
		c2 = convolution_ll(arlst[i], blst[i]);
		rep3(j, n-1, 2*n-1) clst[i][j-(n-1)] = c0[j] + c1[j] + c2[j];
	}
	ll res = 0;
	rep(i, n) {
		ll val = 0;
		rep(j, 5) val += clst[j][i] << j;
		res = max(res, val);
	}
	cout << res << endl;
	return 0;
}
