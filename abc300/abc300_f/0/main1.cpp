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

const int INF = (int)(1e9);

int main() {
	int n, m;
	ll k;
	string s;
	cin >> n >> m >> k >> s;
	int xcnt = count(all(s), 'x');
	if (k == (ll)xcnt*m) {
		cout << ((ll)n*m) << endl;
		return 0;
	}
	ll res = 0;
	if (m == 1) {
		int ri = 0, xval = 0;
		rep(li, n) {
			while (ri<n && (xval<k || (xval==k&&s[ri]!='x'))) {
				if (s[ri] == 'x') ++xval;
				++ri;
			}
			res = max(res, (ll)ri-li);
			if (s[li] == 'x') --xval;
		}
	}
	else {
		ll aval = k / xcnt, bval = k % xcnt;
		string t = s + s;
		int xval = 0, ri = 0;
		rep(li, 2*n) {
			while (ri<n*2 && (xval<bval || (xval==bval&&t[ri]!='x'))) {
				if (t[ri] == 'x') ++xval;
				++ri;
			}
			ll rval = min((ll)n*m, ri+(ll)n*aval);
			res = max(res, rval-li);
			if (t[li] == 'x') --xval;
		}
	}
	cout << res << endl;
	return 0;
}
