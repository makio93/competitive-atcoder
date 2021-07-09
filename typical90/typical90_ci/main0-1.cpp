#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力解答、WA

const int INF = (int)(2e9);

int main() {
	int n, p, k;
	cin >> n >> p >> k;
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	vector<int> tar = { k, k+1 }, rval = { INF, INF };
	bool no = false;
	rep(i1, 2) {
		int l = 0, r = p + 5;
		while (r-l > 1) {
			int c = (l + r) / 2;
			auto b = a;
			rep(i, n) rep(j, n) if (a[i][j] == -1) b[i][j] = c;
			rep(j2, n) rep(i, n) rep3(j, i+1, n) {
				int di = min({b[i][j], b[j][i], b[i][j2]+b[j2][j], b[j][j2]+b[j2][i]});
				b[i][j] = b[j][i] = di;
			}
			int cnt = 0;
			rep(i, n) rep3(j, i+1, n) if (b[i][j] <= p) ++cnt;
			if (cnt < tar[i1]) r = c;
			else l = c;
		}
		if (tar[i1]==k && l==r) no = true;
		rval[i1] = l;
	}
	if (rval[0] == p+4) cout << "Infinity" << endl;
	else if (no) cout << 0 << endl;
	else cout << (max(0, rval[0]-rval[1])) << endl;
	return 0;
}
