#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
	int w, n;
	cin >> w >> n;
	vector<int> l(n), r(n), v(n);
	rep(i, n) cin >> l[i] >> r[i] >> v[i];
	vector<ll> dp(w+1, -1);
	dp[0] = 0;
	rep(i, n) {
		vector<vector<ll>> add(w+2), sub(w+2);
		rep(j, w) if (dp[j] != -1) {
			if (j+l[i] > w) break;
			int li = j+l[i], ri = min(w+1, j+r[i]+1);
			ll val = dp[j] + v[i];
			add[li].push_back(val);
			sub[ri].push_back(val);
		}
		map<ll, int> vals;
		rep(j, w+2) {
			if (!add[j].empty()) for (ll ai : add[j]) vals[ai]++;
			if (!sub[j].empty()) for (ll bi : sub[j]) {
				vals[bi]--;
				if (vals[bi] == 0) vals.erase(bi);
			}
			if (vals.empty() || j>w) continue;
			if (dp[j] == -1) dp[j] = 0;
			ll nval = vals.rbegin()->first;
			dp[j] = max(dp[j], nval);
		}
	}
	if (dp[w] == -1) cout << -1 << endl;
	else cout << dp[w] << endl;
	return 0;
}
