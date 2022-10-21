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
	vector<int> c(n), g(n);
	rep(i, n) {
		int xi;
		cin >> xi;
		--xi;
		g[i] = xi;
	}
	rep(i, n) cin >> c[i];
	vector<int> visited(n);
	ll res = 0;
	int mval = INF;
	auto dfs = [&](auto dfs, int vi) -> int {
		visited[vi] = 1;
		if (visited[g[vi]] == -1) {
			visited[vi] = -1;
			return -1;
		}
		else if (visited[g[vi]] == 1) {
			mval = c[vi];
			visited[vi] = -1;
			return g[vi];
		}
		else {
			int rval = dfs(dfs, g[vi]);
			visited[vi] = -1;
			if (rval != -1) {
				if (rval != vi) {
					mval = min(mval, c[vi]);
					return rval;
				}
				else {
					mval = min(mval, c[vi]);
					res += mval;
					mval = INF;
					return -1;
				}
			}
			else return -1;
		}
	};
	rep(i, n) if (visited[i] == 0) dfs(dfs, i);
	cout << res << endl;
	return 0;
}
