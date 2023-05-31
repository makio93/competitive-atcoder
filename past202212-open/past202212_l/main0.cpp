// バチャ本番AC

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

const int INF = (int)(2e9);

int main() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		return make_pair(l[li], -r[li]) > make_pair(l[ri], -r[ri]);
	});
	vector<int> dp(n, INF);
	rep(i, n) *upper_bound(all(dp), r[ord[i]]) = r[ord[i]];
	int res = 0;
	rep(i, n) if (dp[i] < INF) res = i + 1;
	cout << res << endl;
	return 0;
}
