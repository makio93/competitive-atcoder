// 解説AC1

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
	mint mxsum = 0, mnsum = 0;
	stack<pair<int, mint>> mxdat, mndat;
	rep(i, n) {
		mint mxval = dp[i], mnval = dp[i];
		while (!mxdat.empty() && a[i]>mxdat.top().first) {
			mxsum -= mxdat.top().second * mxdat.top().first;
			mxval += mxdat.top().second;
			mxdat.pop();
		}
		mxsum += mxval * a[i];
		mxdat.emplace(a[i], mxval);
		while (!mndat.empty() && a[i]<mndat.top().first) {
			mnsum -= mndat.top().second * mndat.top().first;
			mnval += mndat.top().second;
			mndat.pop();
		}
		mnsum += mnval * a[i];
		mndat.emplace(a[i], mnval);
		dp[i+1] = mxsum - mnsum;
	}
	cout << dp[n].val() << endl;
	return 0;
}
