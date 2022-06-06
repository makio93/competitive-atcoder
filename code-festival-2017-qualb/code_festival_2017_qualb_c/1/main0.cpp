// 学習1回目,自力AC(ヒント有)

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
	vector<vector<int>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> col(n);
	auto dfs = [&](auto dfs, int vi=0, int ci=1) -> bool {
		col[vi] = ci;
		for (int ti : g[vi]) if (col[ti]!=-ci && (col[ti]!=0 || !dfs(dfs, ti, -ci))) return false;
		return true;
	};
	if (dfs(dfs)) {
		int cnt1 = 0, cnt2 = 0;
		rep(i, n) {
			if (col[i] == 1) cnt1++;
			else cnt2++;
		}
		cout << ((ll)cnt1*cnt2-m) << endl;
	}
	else cout << ((ll)n*(n-1)/2-m) << endl;
	return 0;
}
