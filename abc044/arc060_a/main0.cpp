// バチャ本番,自力AC

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
	int n, a;
	cin >> n >> a;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	int add = a * n, vlen = 50 * n + add + 1;
	vector<ll> dp(vlen), ndp;
	rep(i, n) {
		ndp = dp;
		int sval = x[i] - a;
		rep(j, vlen) if (j+sval>=0 && j+sval<vlen) ndp[j+sval] += dp[j];
		ndp[add+sval]++;
		swap(ndp, dp);
	}
	cout << dp[add] << endl;
	return 0;
}
