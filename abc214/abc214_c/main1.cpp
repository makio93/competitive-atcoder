// 解説AC

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
	vector<int> s(n), t(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	vector<ll> dp(n);
	rep(i, n) dp[i] = t[i];
	rep(i, n*2-1) chmin(dp[(i+1)%n], dp[i%n]+s[i%n]);
	rep(i, n) cout << dp[i] << endl;
	return 0;
}
