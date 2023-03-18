// 学習1回目,バチャ,自力AC2

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
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	vector<int> dp(n);
	rep3(i, 1, n) {
		if (h[i] <= h[i-1]) dp[i] = dp[i-1] + 1;
		else dp[i] = 0;
	}
	int res = *max_element(all(dp));
	cout << res << endl;
	return 0;
}
