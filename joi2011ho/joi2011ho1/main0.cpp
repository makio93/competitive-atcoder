// 自力AC1

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
const string tar = "JOI";

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector<string> s(m);
	rep(i, m) cin >> s[i];
	vector<int> a(k), b(k), c(k), d(k);
	rep(i, k) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; b[i]--;
	}
	vector<vector<vector<int>>> ccnt(3, vector<vector<int>>(m+1, vector<int>(n+1)));
	rep(i, m) rep(j, n) rep(i2, 3) {
		int val = s[i][j] == tar[i2] ? 1 : 0;
		ccnt[i2][i+1][j+1] = ccnt[i2][i][j+1] + ccnt[i2][i+1][j] - ccnt[i2][i][j] + val;
	}
	rep(i, k) rep(j, 3) cout << (ccnt[j][c[i]][d[i]]-ccnt[j][a[i]][d[i]]-ccnt[j][c[i]][b[i]]+ccnt[j][a[i]][b[i]]) << (j<2?' ':'\n');
	return 0;
}
