// 学習1回目,自力AC

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
	vector<vector<int>> di(c, vector<int>(c)), ci(n, vector<int>(n));
	rep(i, c) rep(j, c) cin >> di[i][j];
	rep(i, n) rep(j, n) cin >> ci[i][j];
	vector<vector<int>> dvals(c, vector<int>(3));
	rep(i1, c) rep(i, n) rep(j, n) dvals[i1][(i+j+2)%3] += di[ci[i][j]-1][i1];
	int res = INF;
	rep(i1, c) rep(i2, c) rep(i3, c) {
		if (i1==i2 || i2==i3 || i1==i3) continue;
		res = min(res, dvals[i1][0]+dvals[i2][1]+dvals[i3][2]);
	}
	cout << res << endl;
	return 0;
}
