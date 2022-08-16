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
	int n;
	cin >> n;
	vector<vector<int>> a(2, vector<int>(n));
	rep(i, 2) rep(j, n) cin >> a[i][j];
	vector<int> lsum(n+1), rsum(n+1);
	rep(i, n) lsum[i+1] += lsum[i] + a[0][i];
	repr(i, n) rsum[i] += rsum[i+1] + a[1][i];
	int res = 0;
	rep(i, n) res = max(res, a[0][i]+a[1][i]+lsum[i]+rsum[i+1]);
	cout << res << endl;
	return 0;
}
