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

// 本番中に実装、TLE

int main() {
	int n;
	cin >> n;
	vector<vector<int>> val(n, vector<int>(5));
	rep(i, n) rep(j, 5) cin >> val[i][j];
	vector<int> rid = { 0, 1, 2 };
	int nval = (int)(2e9);
	rep(i, 5) {
		int tval = 0;
		rep(j, 3) tval = max(tval, val[rid[j]][i]);
		nval = min(nval, tval);
	}
	rep3(i, 3, n) {
		pair<int, int> pval = { nval, -1 };
		rep(j, 3) {
			int nval2 = (int)(2e9);
			rep(i2, 5) {
				int tval = 0;
				rep(j2, 3) {
					if (j2 == j) tval = max(tval, val[i][i2]);
					else tval = max(tval, val[rid[j2]][i2]);
				}
				nval2 = min(nval2, tval);
			}
			pval = max(pval, { nval2, j });
		}
		if (pval.second != -1) {
			rid[pval.second] = i;
			nval = pval.first;
		}
	}
	cout << nval << endl;
	return 0;
}
