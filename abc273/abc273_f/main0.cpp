// 自力WA

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

const ll LINF = (ll)(1e18);

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> y(n), z(n);
	rep(i, n) cin >> y[i];
	rep(i, n) cin >> z[i];
	vector<pair<int, int>> llst(1, { 0, 0 }), rlst(1, { 0, 0 });
	if (x > 0) rlst.emplace_back(x, 0);
	else llst.emplace_back(x, 0);
	rep(i, n) {
		if (y[i] > 0) rlst.emplace_back(y[i], i+1);
		else llst.emplace_back(y[i], i+1);
	}
	rep(i, n) {
		if (z[i] > 0) rlst.emplace_back(z[i], -(i+1));
		else llst.emplace_back(z[i], -(i+1));
	}
	sort(all(rlst));
	sort(all(llst), greater<pair<int, int>>());
	int llen = llst.size()-1, rlen = rlst.size()-1;
	vector<vector<vector<ll>>> dp(2*n+2, vector<vector<ll>>(2, vector<ll>(llen+1, LINF)));
	dp[0][0][0] = dp[0][1][0] = 0;
	ll res = LINF;
	set<int> keys;
	rep(i, 2*n+1) {
		auto tk = keys;
		int lmx = min(llen, i);
		repr(j, lmx+1) {
			int li = j, ri = i - li;
			if (li+1 <= llen) {
				if (llst[li+1].second > 0) {
					if (tk.find(llst[li+1].second) != tk.end()) {
						if (dp[i][0][j] != LINF) dp[i+1][0][li+1] = min(dp[i+1][0][li+1], dp[i][0][j]+abs((ll)(llst[li+1].first)-llst[li].first));
						if (dp[i][1][j] != LINF) dp[i+1][0][li+1] = min(dp[i+1][0][li+1], dp[i][1][j]+abs((ll)(llst[li+1].first)-llst[ri].first));
					}
				}
				else {
					if (dp[i][0][j] != LINF) dp[i+1][0][li+1] = min(dp[i+1][0][li+1], dp[i][0][j]+abs((ll)(llst[li+1].first)-llst[li].first));
					if (dp[i][1][j] != LINF) dp[i+1][0][li+1] = min(dp[i+1][0][li+1], dp[i][1][j]+abs((ll)(llst[li+1].first)-llst[ri].first));
					if (llst[li+1].second == 0) res = min(res, dp[i+1][0][li+1]);
				}
			}
			if (ri+1 <= rlen) {
				if (rlst[ri+1].second > 0) {
					if (tk.find(rlst[ri+1].second) != tk.end()) {
						if (dp[i][0][j] != LINF) dp[i+1][1][li] = min(dp[i+1][1][li], dp[i][0][j]+abs((ll)(rlst[ri+1].first)-rlst[li].first));
						if (dp[i][1][j] != LINF) dp[i+1][1][li] = min(dp[i+1][1][li], dp[i][1][j]+abs((ll)(rlst[ri+1].first)-rlst[ri].first));
					}
				}
				else {
					if (dp[i][0][j] != LINF) dp[i+1][1][li] = min(dp[i+1][1][li], dp[i][0][j]+abs((ll)(rlst[ri+1].first)-rlst[li].first));
					if (dp[i][1][j] != LINF) dp[i+1][1][li] = min(dp[i+1][1][li], dp[i][1][j]+abs((ll)(rlst[ri+1].first)-rlst[ri].first));
					if (rlst[ri+1].second == 0) res = min(res, dp[i+1][1][li]);
				}
			}
			if (llst[li].second < 0) tk.erase(-llst[li].second);
			if (ri+1<=rlen && rlst[ri+1].second<0) tk.insert(-rlst[ri+1].second);
		}
		if (i < llen) {
			if (llst[i+1].second < 0) keys.insert(-llst[i+1].second);
		}
		else {
			int ri = (i+1) - llen;
			if (rlst[ri+1].second < 0) keys.insert(-rlst[ri+1].second);
		}
	}
	if (res == LINF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
