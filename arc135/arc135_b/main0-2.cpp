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

// 本番WA2

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
		vals[0] = max(0LL, s[0] - s[1]);
		vals[1] = s[0] - vals[0];
		rep3(i, 1, n) {
			if (s[i] >= s[i-1]) {
				vals[i+2] = s[i] - s[i-1];
			}
			else {
				ll sval = s[i] - vals[i] - vals[i+1];
				if (sval < 0) {
					ok = false;
					break;
				}
				vals[i+2] = sval;
			}
		}
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
