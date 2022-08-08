// 解説AC1

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
	int n, m;
	cin >> n >> m;
	vector<vector<vector<vector<int>>>> res(n+1, vector<vector<vector<int>>>(m+1));
	auto dfs = [&](auto dfs, int di, int pval) -> void {
		if (!res[di][pval].empty()) return;
		if (di == 1) {
			rep3(i, 1, pval+1) res[di][pval].push_back({ i });
			return;
		}
		rep3(i, 1, pval+1) {
			dfs(dfs, di-1, i-1);
			for (auto& vlst : res[di-1][i-1]) {
				res[di][pval].push_back(vlst);
				res[di][pval].back().push_back(i);
			}
		}
	};
	dfs(dfs, n, m);
	sort(all(res[n][m]));
	for (auto& vi : res[n][m]) {
		rep(i, vi.size()) cout << vi[i] << ' ';
		cout << endl;
	}
	return 0;
}
