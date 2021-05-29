#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

const ll mod = (ll)(1e9) + 7;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(6));
	rep(i, n) rep(j, 6) cin >> a[i][j];
	ll res = 1;
	rep(i, n) {
		ll sum = 0;
		rep(j, 6) sum += a[i][j];
		res = res * sum % mod;
	}
	cout << res << endl;
	return 0;
}
