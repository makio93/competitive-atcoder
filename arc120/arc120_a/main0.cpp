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
	int n;
	cin >> n;
	vector<ll> a(n), s(n+1), m(n+1);
	rep(i, n) cin >> a[i];
	rep(i, n) s[i+1] = s[i] + a[i];
	rep(i, n) m[i+1] = max(m[i], a[i]);
	ll sum = 0;
	rep(i, n) {
		sum += s[i+1];
		ll res = sum + m[i+1] * (i+1);
		cout << res << endl;
	}
	return 0;
}
