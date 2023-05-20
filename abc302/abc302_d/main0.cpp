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

const int INF = (int)(1e9);

int main() {
	int n, m;
	ll d;
	cin >> n >> m >> d;
	vector<ll> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	sort(all(a));
	sort(all(b));
	ll res = -1;
	repr(i, n) {
		int id = upper_bound(all(b), a[i]) - b.begin() - 1;
		if (id>=0 && a[i]-b[id]<=d) res = max(res, a[i]+b[id]);
	}
	repr(i, m) {
		int id = upper_bound(all(a), b[i]) - a.begin() - 1;
		if (id>=0 && b[i]-a[id]<=d) res = max(res, b[i]+a[id]);
	}
	cout << res << endl;
	return 0;
}
