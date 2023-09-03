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
	vector<int> a(n), b(n), c(n), d(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<vector<bool>> area(100, vector<bool>(100));
	rep(i, n) rep3(j1, c[i], d[i]) rep3(j2, a[i], b[i]) area[j1][j2] = true;
	int res = 0;
	rep(i, 100) res += count(all(area[i]), true);
	cout << res << endl;
	return 0;
}
