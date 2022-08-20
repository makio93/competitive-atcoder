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

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w)), b(w, vector<int>(h));
	rep(i, h) rep(j, w) {
		cin >> a[i][j];
		b[j][i] = a[i][j];
	}
	rep(i, w) rep(j, h) printf("%d%c", b[i][j], (j<h-1?' ':'\n'));
	return 0;
}
