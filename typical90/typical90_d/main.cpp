// 自力で実装、AC

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
	vector<int> hsum(h), wsum(w);
	rep(i, h) rep(j, w) hsum[i] += a[i][j];
	rep(i, w) rep(j, h) wsum[i] += a[j][i];
	rep(i, h) rep(j, w) cout << (hsum[i]+wsum[j]-a[i][j]) << (j<w-1?' ':'\n');
	return 0;
}
