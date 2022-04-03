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
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	bool res = true;
	rep(i1, h-1) rep(j1, w-1) rep3(i2, i1+1, h) rep3(j2, j1+1, w) {
		if (a[i1][j1]+a[i2][j2] > a[i2][j1]+a[i1][j2]) res = false;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
