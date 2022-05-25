// バチャ,自力AC

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
	ll n;
	cin >> n;
	pair<ll, ll> ab = { 1, n };
	for (ll a=1; a*a<=n; ++a) if (n%a == 0) ab = max(ab, { a, n/a });
	int res = max(to_string(ab.first).length(), to_string(ab.second).length());
	cout << res << endl;
	return 0;
}
