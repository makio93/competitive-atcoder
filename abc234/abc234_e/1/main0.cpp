// 学習1回目,バチャ本番,自力AC

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
	ll x;
	cin >> x;
	string xstr = to_string(x);
	int xlen = xstr.length();
	if (xlen == 1) {
		cout << x << endl;
		return 0;
	}
	ll res = stoll(string(xlen+1, '1'));
	rep3(i, 1, 10) rep3(d, -9, 10) {
		int di = i;
		ll val = di;
		bool ok = true;
		rep(j, xlen-1) {
			di += d;
			if (di<0 || di>9) {
				ok = false;
				break;
			}
			val = val * 10 + di;
		}
		if (!ok) continue;
		if (val >= x) res = min(res, val);
	}
	cout << res << endl;
	return 0;
}
