// 解説AC2

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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<mint> dp(n+1);
	dp[0] = 1;
	stack<pair<int, mint>> mxstk, mnstk;
	mint mxsum = 0, mnsum = 0;
	rep(i, n) {
		mint mxval = dp[i], mnval = dp[i];
		while (!mxstk.empty() && mxstk.top().first<a[i]) {
			mxsum -= mxstk.top().second * mxstk.top().first;
			mxval += mxstk.top().second;
			mxstk.pop();
		}
		mxsum += mxval * a[i];
		mxstk.emplace(a[i], mxval);
		while (!mnstk.empty() && mnstk.top().first>a[i]) {
			mnsum -= mnstk.top().second * mnstk.top().first;
			mnval += mnstk.top().second;
			mnstk.pop();
		}
		mnsum += mnval * a[i];
		mnstk.emplace(a[i], mnval);
		dp[i+1] = mxsum - mnsum;
	}
	cout << dp[n].val() << endl;
	return 0;
}
