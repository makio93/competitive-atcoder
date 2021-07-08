#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力解答、WA

const ll INF = (ll)(1e15);

int main() {
	ll n, p, k;
	cin >> n >> p >> k;
	vector<vector<ll>> a(n, vector<ll>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	vector<ll> tar = { k, k+1 }, rval = { INF, INF };
	bool no = false;
	rep(i1, 2) {
		ll l = 0, r = p + 5;
		while (r-l > 1) {
			ll c = (l + r) / 2;
			auto b = a;
			rep(i, n) rep(j, n) if (a[i][j] == -1LL) b[i][j] = c;
			rep(j2, n) rep(i, n) rep(j, n) {
				b[i][j] = min({b[i][j], b[i][j2]+b[j2][j], b[j][j2]+b[j2][i]});
			}
			ll cnt = 0;
			rep(i, n) rep3(j, i+1, n) if (b[i][j] <= p) ++cnt;
			if (cnt < tar[i1]) r = c;
			else l = c;
		}
		if (tar[i1]==k && l==r) no = true;
		rval[i1] = l;
	}
	if (rval[0] == p+4) cout << "Infinity" << endl;
	else if (no) cout << 0 << endl;
	else cout << (max(0LL, rval[0]-rval[1])) << endl;
	return 0;
}
