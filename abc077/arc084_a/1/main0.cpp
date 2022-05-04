// 学習1回目,自力AC

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
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];
	sort(all(a));
	sort(all(b));
	sort(all(c));
	vector<ll> bsum(n+1);
	repr(i, n) bsum[i] = bsum[i+1] + (n - distance(c.begin(), upper_bound(all(c), b[i])));
	ll res = 0;
	rep(i, n) res += bsum[distance(b.begin(), upper_bound(all(b), a[i]))];
	cout << res << endl;
	return 0;
}
