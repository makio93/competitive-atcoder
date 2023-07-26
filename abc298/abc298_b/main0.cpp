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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	rep(i, n) rep(j, n) cin >> b[i][j];
	function<void(void)> a_roll = [&]() {
		vector<vector<int>> tmp(n, vector<int>(n));
		rep(i, n) rep(j, n) tmp[i][j] = a[j][n-1-i];
		swap(tmp, a);
	};
	function<bool(void)> is_same = [&]() {
		rep(i, n) rep(j, n) if (a[i][j] == 1 && b[i][j] == 0) return false;
		return true;
	};
	rep(ii, 4) {
		if (is_same()) {
			cout << "Yes" << endl;
			return 0;
		}
		a_roll();
	}
	cout << "No" << endl;
	return 0;
}
