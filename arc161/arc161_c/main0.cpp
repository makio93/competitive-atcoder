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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<vector<int>> g(n);
		rep(i, n-1) {
			int ai, bi;
			cin >> ai >> bi;
			--ai; --bi;
			g[ai].push_back(bi);
			g[bi].push_back(ai);
		}
		string s;
		cin >> s;
		vector<int> res(n, -1);
		vector<vector<bool>> dp(n, vector<bool>(4));
		function<void(int,int)> dfs = [&](int vi, int pi) {
			int ncnt = s[vi] == 'B' ? 1 : 0;
			for (const int& ti : g[vi]) if (ti != pi) dfs(ti, vi);
			bool fin = false;
			rep(i1, 4) {
				int pcnt = (i1>>1) & 1, vcnt = i1 & 1;
				int id0 = (vcnt << 1) | ncnt, id1 = (vcnt << 1) | (1-ncnt);
				int bcnt = (pi != -1 && pcnt == ncnt) ? 1 : 0;
				bool ok = true;
				for (const int& ti : g[vi]) if (ti != pi) {
					if (dp[ti][id0]) ++bcnt;
					else if (!dp[ti][id1]) {
						ok = false;
						break;
					}
				}
				if (!ok || bcnt<=(int)(g[vi].size())/2) continue;
				dp[vi][i1] = true;
				if (!fin) {
					fin = true;
					for (const int& ti : g[vi]) if (ti != pi) {
						if (dp[ti][id0]) res[ti] = ncnt;
						else res[ti] = 1-ncnt;
					}
					if (pi == -1) res[vi] = vcnt;
				}
			}
		};
		dfs(0, -1);
		if ((int)(count(all(res), -1)) > 0) cout << -1 << endl;
		else {
			string sres;
			rep(i, n) {
				if (res[i] == 1) sres.push_back('B');
				else sres.push_back('W');
			}
			cout << sres << endl;
		}
	}
	return 0;
}
