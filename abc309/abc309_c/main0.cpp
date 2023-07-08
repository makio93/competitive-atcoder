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
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<pair<int, int>> ab(n);
	rep(i, n) ab[i] = { a[i] + 1, b[i] };
	sort(all(ab));
	ll val = accumulate(all(b), 0LL);
	if (val <= k) {
		cout << 1 << endl;
		return 0;
	}
	int res = -1;
	rep(i, n) {
		val -= ab[i].second;
		if (val <= k) {
			res = ab[i].first;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
