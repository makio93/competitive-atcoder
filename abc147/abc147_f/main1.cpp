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
	int n, x, d;
	cin >> n >> x >> d;
	if (d<0 || (d==0&&x<0)) {
		x *= -1;
		d *= -1;
	}
	ll res = 0;
	if (d == 0) res = x == 0 ? 1 : n + 1;
	else {
		auto calc = [&](int xi, int li, int ri) -> ll {
			return (ll)xi * x + ((ll)d * li + (ll)d * (ri-1)) * (ri-li) / 2;
		};
		unordered_map<int, unordered_map<ll, ll>> vlst;
		vlst[0][0] = 1;
		rep(i, n) {
			int dm = x >= 0 ? (ll)x * (i+1) % d : (d - abs((ll)x * (i+1)) % d) % d;
			pair<ll, ll> tval = { calc(i+1, 0, i+1), calc(i+1, n-(i+1), n)+1 };
			if (vlst[dm].find(tval.first) == vlst[dm].end()) vlst[dm][tval.first] = tval.second;
			else vlst[dm][tval.first] = max(vlst[dm][tval.first], tval.second);
		}
		for (auto& vpi : vlst) {
			auto& tvi = vpi.second;
			vector<pair<ll, ll>> vi(all(tvi));
			sort(all(vi));
			int m = vi.size();
			ll mval = -LINF;
			rep(i, m) {
				mval = max(mval, vi[i].second);
				if (i+1 < m) res += (min(vi[i+1].first, mval) - vi[i].first + d - 1) / d;
				else res += (mval - vi[i].first + d - 1) / d;
			}
		}
	}
	cout << res << endl;
	return 0;
}
