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
	int n, m, p0;
	cin >> n >> m;
	vector<string> c(n), d(m);
	rep(i, n) cin >> c[i];
	vector<int> p(m);
	rep(i, m) cin >> d[i];
	cin >> p0;
	rep(i, m) cin >> p[i];
	unordered_map<string, int> dp;
	rep(i, m) dp[d[i]] = p[i];
	int res = 0;
	rep(i, n) {
		if (dp.find(c[i]) != dp.end()) res += dp[c[i]];
		else res += p0;
	}
	cout << res << endl;
	return 0;
}
