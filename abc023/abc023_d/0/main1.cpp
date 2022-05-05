// 練習0,解説AC

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
	int n;
	cin >> n;
	vector<int> h(n), s(n);
	rep(i, n) cin >> h[i] >> s[i];
	ll l = 0, r = LINF;
	while (r-l > 1) {
		ll c = l + (r-l) / 2;
		vector<ll> tlst(n);
		bool ok = true;
		rep(i, n) {
			if (c < (ll)h[i]) {
				ok = false;
				break;
			}
			tlst[i] = (c-h[i]) / s[i];
		}
		if (ok) {
			sort(all(tlst));
			rep(i, n) if (tlst[i] < i) {
				ok = false;
				break;
			}
		}
		if (ok) r = c;
		else l = c;
	}
	cout << r << endl;
	return 0;
}
