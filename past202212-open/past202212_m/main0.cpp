// バチャ本番AC

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
	vector<vector<pair<int, int>>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].emplace_back(vi, i);
		g[vi].emplace_back(ui, i);
	}
	vector<int> svals(n);
	function<void(int,int)> dfs0 = [&](int vi, int pi) {
		svals[vi]++;
		for (const auto& tpi : g[vi]) if (tpi.first != pi) {
			dfs0(tpi.first, vi);
			svals[vi] += svals[tpi.first];
		}
	};
	dfs0(0, -1);
	ll sub = 0;
	function<void(int,int,int,int)> calc = [&](int vi, int pi, int li, int ri) {
		for (const auto& tpi : g[vi]) if (tpi.first != pi) {
			if (pi == -1) {
				sub += (ll)tpi.second * (tpi.second + 1) / 2 * svals[tpi.first];
				sub += (ll)((n-2) - tpi.second) * ((n-2) - tpi.second + 1) / 2 * svals[tpi.first];
				calc(tpi.first, vi, tpi.second, tpi.second);
			}
			else if (tpi.second < li) {
				sub += (ll)((n-2) - ri + 1) * (li - tpi.second) * svals[tpi.first];
				calc(tpi.first, vi, tpi.second, ri);
			}
			else if (tpi.second > ri) {
				sub += (ll)(tpi.second - ri) * (li + 1) * svals[tpi.first];
				calc(tpi.first, vi, li, tpi.second);
			}
			else calc(tpi.first, vi, li, ri);
		}
	};
	calc(0, -1, -1, -1);
	ll res = (ll)n * (n-1) / 2 * n - sub;
	cout << res << endl;
	return 0;
}
