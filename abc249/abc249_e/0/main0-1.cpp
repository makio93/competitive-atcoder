// 自力TLE

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
	int n, p;
	cin >> n >> p;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	map<pair<int, int>, ll> dp;
	dp[{2, 1}] = 26;
	rep3(i, 1, n) {
		map<pair<int, int>, ll> ndp;
		for (auto pi : dp) {
			ndp[{ min(n, pi.first.first+2), 1 }] = (ndp[{ min(n, pi.first.first+2), 1 }] + pi.second * 25) % p;
			int add = to_string(pi.first.second).length() != to_string(pi.first.second+1).length() ? 1 : 0;
			ndp[{ min(n, pi.first.first+add), pi.first.second+1 }] = (ndp[{ min(n, pi.first.first+add), pi.first.second+1 }] + pi.second) % p;
		}
		swap(ndp, dp);
	}
	ll res = 0;
	for (auto pi : dp) if (pi.first.first < n) res = (res + pi.second) % p;
	cout << res << endl;
	return 0;
}
