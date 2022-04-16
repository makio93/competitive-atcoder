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

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	if (k == 1) {
		cout << "Infinity" << endl;
		return 0;
	}
	vector<vector<bool>> used(n, vector<bool>(n));
	int res = 0;
	rep(i, n) rep3(j, i+1, n) if (!used[i][j]) {
		int cnt = 2;
		vector<int> check;
		check.push_back(i);
		check.push_back(j);
		rep3(i2, j+1, n) if (!used[i][i2]) {
			if ((ll)(y[i2]-y[i])*(x[j]-x[i]) == (ll)(y[j]-y[i])*(x[i2]-x[i])) {
				++cnt;
				check.push_back(i2);
			}
		}
		if (cnt >= k) ++res;
		int m = check.size();
		rep(i2, m) rep3(j2, i2+1, m) used[check[i2]][check[j2]] = used[check[j2]][check[i2]] = true;
	}
	cout << res << endl;
	return 0;
}
