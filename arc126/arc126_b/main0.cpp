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

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	rep(i, m) cin >> a[i] >> b[i];
	vector<pair<int, int>> ab(m);
	rep(i, m) ab[i] = { a[i], -b[i] };
	sort(all(ab));
	vector<int> blst(m);
	rep(i, m) blst[i] = -ab[i].second;
	vector<int> dp(m+1, INF);
	rep(i, m) {
		*lower_bound(all(dp), blst[i]) = blst[i];
	}
	int res = 0;
	rep(i, m+1) if (dp[i] != INF) res = max(res, i+1);
	cout << res << endl;
	return 0;
}
