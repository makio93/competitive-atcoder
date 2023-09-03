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

const ll LINF = (ll)(1e18);

int main() {
	int n, d, p;
	cin >> n >> d >> p;
	vector<int> f(n);
	rep(i, n) cin >> f[i];
	sort(f.rbegin(), f.rend());
	vector<ll> s(n+1);
	repr(i, n) s[i] = s[i+1] + f[i];
	ll add = 0, res = (ll)p * ((n+d-1) / d);
	for (int i=0; i<n; i+=d) {
		res = min(res, s[i]+add);
		add += p;
	}
	cout << res << endl;
	return 0;
}
