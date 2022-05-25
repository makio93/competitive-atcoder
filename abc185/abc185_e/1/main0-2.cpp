// バチャ本番WA2

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
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	rep(i, n) rep(j, m) {
		dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		if (a[i] == b[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
	}
	int iid = n, jid = m;
	vector<pair<int, int>> lst;
	while (iid>0 && jid>0) {
		if (a[iid-1] == b[jid-1]) {
			lst.emplace_back(iid-1, jid-1);
			--iid; --jid;
		}
		else {
			if (dp[iid-1][jid] == dp[iid][jid]) --iid;
			else --jid;
		}
	}
	lst.emplace_back(-1, -1);
	reverse(all(lst));
	lst.emplace_back(n, m);
	int len = lst.size();
	int res = 0;
	rep(i, len-1) {
		int val1 = lst[i+1].first - lst[i].first - 1, val2 = lst[i+1].second - lst[i].second - 1;
		res += abs(val1-val2);
		res += min(val1, val2);
	}
	cout << res << endl;
	return 0;
}
