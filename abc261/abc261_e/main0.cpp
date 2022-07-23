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
	int n, c;
	cin >> n >> c;
	vector<int> t(n), a(n);
	rep(i, n) cin >> t[i] >> a[i];
	vector<vector<int>> vals(n+1, vector<int>(2));
	vals[0][1] = (1<<30) - 1;
	rep(i, n) rep(j, 2) {
		if (t[i] == 1) vals[i+1][j] = vals[i][j] & a[i];
		if (t[i] == 2) vals[i+1][j] = vals[i][j] | a[i];
		if (t[i] == 3) vals[i+1][j] = vals[i][j] ^ a[i];
	}
	rep(i, n) {
		int nc = 0;
		rep(j, 30) nc |= vals[i+1][(c>>j)&1] & (1<<j);
		c = nc;
		cout << c << endl;
	}
	return 0;
}
