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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> aval(n);
	rep3(i, 1, n) {
		int li = 0, ri = i + 1;
		rep3(j, li+1, ri) aval[i] += a[min(j-li,ri-j)-1];
	}
	vector<ll> dp(n+1, -LINF);
	dp[0] = 0;
	rep3(i, 1, n+1) rep(j, i) chmax(dp[i], dp[j]+aval[i-j-1]);
	cout << dp[n] << endl;
	return 0;
}
