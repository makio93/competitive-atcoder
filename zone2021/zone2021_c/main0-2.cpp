#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

// 本番終了後に実装、WA or TLE

constexpr int INF = (1e9) + 1;
constexpr int rt = 750;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> val(n, vector<int>(5));
	rep(i, n) rep(j, 5) cin >> val[i][j];
	int res = 0;
	rep(i1, 3) {
		vector<pair<int, int>> val2(n);
		rep(j1, n) val2[j1] = { val[j1][i1], j1 };
		sort(val2.rbegin(), val2.rend());
		for (int i=0; i<min(n,rt); ++i) for (int j=i+1; j<min(n,rt); ++j) for (int k=j+1; k<min(n,rt); ++k) {
			int mval = INF;
			rep(j2, 5) mval = min(mval, max({ val[val2[i].second][j2], val[val2[j].second][j2], val[val2[k].second][j2] }));
			res = max(res, mval);
		}
	}
	{
		vector<pair<int, int>> val2(n);
		rep(j1, n) {
			int tval = INF;
			rep(i1, 5) tval = min(tval, val[j1][i1]);
			val2[j1] = { tval, j1 };
		}
		sort(val2.rbegin(), val2.rend());
		for (int i=0; i<min(n,rt); ++i) for (int j=i+1; j<min(n,rt); ++j) for (int k=j+1; k<min(n,rt); ++k) {
			int mval = INF;
			rep(j2, 5) mval = min(mval, max({ val[val2[i].second][j2], val[val2[j].second][j2], val[val2[k].second][j2] }));
			res = max(res, mval);
		}
	}
	cout << res << endl;
	return 0;
}
