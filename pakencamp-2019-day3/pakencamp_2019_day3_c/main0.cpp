// 自力AC

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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> a[i][j];
	ll res = 0;
	rep(i, m) rep3(j, i+1, m) {
		ll sum = 0;
		rep(i2, n) sum += max(a[i2][i], a[i2][j]);
		res = max(res, sum);
	}
	cout << res << endl;
	return 0;
}
