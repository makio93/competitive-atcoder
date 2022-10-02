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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, n) {
		cin >> b[i];
		b[i]--;
	}
	vector<pair<int, int>> ab(n);
	rep(i, n) ab[i] = { a[i], b[i] };
	sort(all(ab));
	rep(i, n) b[i] = ab[i].second;
	vector<int> dp(n+1, INF);
	rep(i, n) *lower_bound(all(dp), b[i]) = b[i];
	int bcnt = 0;
	rep(i, n) if (dp[i] != INF) bcnt = max(bcnt, i+1);
	int res = n + bcnt;
	cout << res << endl;
	return 0;
}
