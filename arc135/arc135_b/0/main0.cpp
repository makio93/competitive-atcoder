// 本番WA1

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
	int n;
	cin >> n;
	vector<ll> s(n);
	rep(i, n) cin >> s[i];
	vector<ll> vals(n+2);
	bool ok = true;
	if (n <= 1) {
		vals[0] = s[0];
	}
	else if (n <= 2) {
		vals[0] = s[0];
		vals[3] = s[1];
	}
	else {
		if (s[n-1] > s[n-2]) {
			ll sval = s[n-1] - s[n-2];
			vals[n+1] += sval;
			s[n-1] -= sval;
		}
		ll sval0 = min({s[n-3], s[n-2], s[n-1]});
		vals[n-1] += sval0;
		s[n-3] -= sval0;
		s[n-2] -= sval0;
		s[n-1] -= sval0;
		if (s[n-1] <= s[n-2]) {
			ll sval = s[n-1];
			vals[n] += sval;
			s[n-1] -= sval;
			s[n-2] -= sval;
		}
		repr(i, n-3) {
			ll sval = min({s[i], s[i+1], s[i+2]});
			vals[i+2] += sval;
			s[i] -= sval;
			s[i+1] -= sval;
			s[i+2] -= sval;
		}
		rep(i, n) if (s[i] > 0) ok = false;
	}
	if (ok) {
		cout << "Yes" << endl;
		rep(i, n+2) printf("%lld%c", vals[i], (i<n+1?' ':'\n'));
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
