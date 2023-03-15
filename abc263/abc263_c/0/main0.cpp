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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> res;
	vector<int> vals;
	auto dfs = [&](auto dfs, int di=0, int pval=0) -> void {
		if (di == n) {
			res.push_back(vals);
			return;
		}
		rep3(i, pval+1, m+1) {
			vals.push_back(i);
			dfs(dfs, di+1, i);
			vals.pop_back();
		}
	};
	dfs(dfs);
	for (auto& vi : res) {
		rep(i, n) cout << (vi[i]) << ' ';
		cout << endl;
	}
	return 0;
}
