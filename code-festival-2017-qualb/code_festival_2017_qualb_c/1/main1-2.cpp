// 解説AC2

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
	auto dfs = [&](int si=0, int ci=1) -> bool {
		stack<pair<int, int>> st;
		st.emplace(si, ci);
		col[si] = ci;
		while (!st.empty()) {
			auto [vi, ci] = st.top(); st.pop();
			for (int ti : g[vi]) {
				if (col[ti] == ci) return false;
				if (col[ti] == -ci) continue;
				st.emplace(ti, -ci);
				col[ti] = -ci; 
			}
		}
		return true;
	};
	if (dfs()) {
		int cnt = (accumulate(all(col), 0) + n) / 2;
		cout << ((ll)cnt*(n-cnt) - m) << endl;
	}
	else cout << ((ll)n*(n-1)/2 - m) << endl;
	return 0;
}
