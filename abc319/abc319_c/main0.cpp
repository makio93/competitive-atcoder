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
	vector<vector<int>> c(3, vector<int>(3));
	rep(i, 3) rep(j, 3) cin >> c[i][j];
	int cnt = 0;
	vector<int> ord(9);
	iota(all(ord), 0);
	do {
		bool ok = true;
		vector<vector<int>> ol(3, vector<int>(3));
		rep(i, 3) rep(j, 3) ol[i][j] = ord[i*3+j];
		rep(i, 3) {
			vector<pair<int, int>> pt;
			rep(j, 3) pt.emplace_back(ol[i][j], c[i][j]);
			sort(all(pt));
			if (pt[0].second == pt[1].second) ok = false;
		}
		rep(i, 3) {
			vector<pair<int, int>> pt;
			rep(j, 3) pt.emplace_back(ol[j][i], c[j][i]);
			sort(all(pt));
			if (pt[0].second == pt[1].second) ok = false;
		}
		{
			vector<pair<int, int>> pt;
			rep(i, 3) pt.emplace_back(ol[i][i], c[i][i]);
			sort(all(pt));
			if (pt[0].second == pt[1].second) ok = false;
		}
		{
			vector<pair<int, int>> pt;
			rep(i, 3) pt.emplace_back(ol[i][2-i], c[i][2-i]);
			sort(all(pt));
			if (pt[0].second == pt[1].second) ok = false;
		}
		if (ok) ++cnt;
	} while (next_permutation(all(ord)));
	int den = 1;
	rep3(i, 1, 10) den *= i;
	double res = cnt / (double)(den);
	printf("%.10f\n", res);
	return 0;
}
