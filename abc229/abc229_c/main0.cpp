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

// 本番AC

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<pair<int, int>> ab(n);
	rep(i, n) ab[i] = { a[i], b[i] };
	sort(ab.rbegin(), ab.rend());
	ll res = 0;
	int sub = w;
	rep(i, n) {
		res += (ll)min(sub, ab[i].second) * ab[i].first;
		sub -= min(sub, ab[i].second);
		if (sub <= 0) break;
	}
	cout << res << endl;
	return 0;
}
