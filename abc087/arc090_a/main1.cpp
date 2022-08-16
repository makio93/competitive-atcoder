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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(2, vector<int>(n));
	rep(i, 2) rep(j, n) cin >> a[i][j];
	int res = 0;
	rep(i, n) {
		int val = 0;
		rep(j, i+1) val += a[0][j];
		rep3(j, i, n) val += a[1][j];
		res = max(res, val);
	}
	cout << res << endl;
	return 0;
}
