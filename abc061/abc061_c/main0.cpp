// 自力AC

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
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<pair<int, int>> ab(n);
	rep(i, n) ab[i] = { a[i], b[i] };
	sort(all(ab));
	int res = 0;
	rep(i, n) {
		if (k > ab[i].second) k -= ab[i].second;
		else {
			res = ab[i].first;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
