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
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	rep(i, n) cin >> s[i] >> t[i];
	unordered_map<string, int> sids;
	rep(i, n) sids[s[i]] = i;
	vector<vector<int>> g(n);
	rep(i, n) if (sids.find(t[i]) != sids.end()) g[sids[t[i]]].push_back(i);
	bool res = true;
	vector<bool> visited(n), finished(n);
	auto dfs = [&](auto dfs, int vi) -> bool {
		visited[vi] = true;
		for (const int& ti : g[vi]) if (!finished[ti] && (visited[ti] || !dfs(dfs, ti))) return false;
		finished[vi] = true;
		return true;
	};
	rep(i, n) if (!finished[i]) {
		if (!dfs(dfs, i)) {
			res = false;
			break;
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
