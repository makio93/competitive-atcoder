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

// 本番AC

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> q[i];
	unordered_map<int, int> qid;
	rep(i, n) qid[q[i]] = i;
	vector<int> dp(n+1, INF);
	rep(i, n) {
		vector<int> pid;
		for (int j=p[i]; j<=n; j+=p[i]) pid.push_back(qid[j]);
		sort(pid.rbegin(), pid.rend());
		for (int pi : pid) *lower_bound(all(dp), pi) = pi;
	}
	int res = 0;
	rep(i, n+1) if (dp[i] != INF) res = max(res, i+1);
	cout << res << endl;
	return 0;
}
