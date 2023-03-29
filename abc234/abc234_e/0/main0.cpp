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

int main() {
	ll x;
	cin >> x;
	string xstr = to_string(x);
	int n = xstr.length();
	ll res = (ll)(2e18);
	vector<int> dig(n+1, -1);
	function<void(int,int,int,int)> calc = [&](int vi, int di, int ri, int mi) -> void {
		if (vi<0 || vi>9) return;
		dig[di] = vi;
		if (di == mi-1) {
			ll val = 0;
			rep(i, mi) {
				val *= 10;
				val += dig[i];
			}
			if (val >= x) res = min(res, val);
			return;
		}
		else {
			calc(vi+ri, di+1, ri, mi);
		}
	};
	rep3(i, 1, 10) rep(j, 9) {
		calc(i, 0, j, n);
		calc(i, 0, j, n+1);
		if (j > 0) {
			calc(i, 0, -j, n);
			calc(i, 0, -j, n+1);
		}
	}
	cout << res << endl;
	return 0;
}
