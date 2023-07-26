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

const ll LINF = (ll)(1e18);

int main() {
	int h, w, t;
	cin >> h >> w >> t;
	vector<vector<ll>> s(h, vector<ll>(w));
	rep(i, h) rep(j, w) cin >> s[i][j];
	vector<ll> a;
	rep(ui, h) rep3(di, ui+1, h+1) rep(li, w) rep3(ri, li+1, w+1) {
		ll aval = 0;
		rep3(i, ui, di) rep3(j, li, ri) aval += s[i][j];
		a.push_back(aval);
	}
	ll res = LINF;
	for (const ll ai : a) {
		vector memo(h, vector(h+1, vector(w, vector(w+1, vector(t+2, -1LL)))));
		function<ll(int, int, int, int, int)> dp = [&](int ui, int di, int li, int ri, int mi) {
			if (memo[ui][di][li][ri][mi] != -1) return memo[ui][di][li][ri][mi];
			if (mi<1 || di<=ui || ri<=li || (di-ui)*(ri-li)<mi) return memo[ui][di][li][ri][mi] = LINF;
			ll val = LINF;
			if (mi == 1) {
				val = 0;
				rep3(i, ui, di) rep3(j, li, ri) val += s[i][j];
				return memo[ui][di][li][ri][mi] = val >= ai ? val : LINF;
			}
			rep3(i, ui+1, di) rep3(k, 1, mi) {
				ll lval = dp(ui, i, li, ri, k), rval = dp(i, di, li, ri, mi-k);
				if (lval == LINF || rval == LINF) continue;
				val = min(val, max(lval, rval));
			}
			rep3(i, li+1, ri) rep3(k, 1, mi) {
				ll lval = dp(ui, di, li, i, k), rval = dp(ui, di, i, ri, mi-k);
				if (lval == LINF || rval == LINF) continue;
				val = min(val, max(lval, rval));
			}
			return memo[ui][di][li][ri][mi] = val;
		};
		ll mval = dp(0, h, 0, w, t+1);
		if (mval == LINF) continue;
		res = min(res, mval-ai);
	}
	cout << res << endl;
	return 0;
}
